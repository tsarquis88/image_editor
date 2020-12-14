#include "image_editor.hpp"

ImageEditor::ImageEditor( )
{
    rain_granularity    =   DEFAULT_RAIN_GRANULARITY;
    bright_step         =   DEFAULT_BRIGHT_STEP;
    contrast_step       =   DEFAULT_CONTRAST_STEP;
    frame_anchor        =   DEFAULT_FRAME_ANCHOR;
    circle_anchor       =   DEFAULT_CIRCLE_ANCHOR;
    kernel_size         =   DEFAULT_KERNEL_SIZE;
}

int
ImageEditor::setup( string image_path )
{    
    ImageEditor::image_path =   image_path;

    image    =   imread( image_path, IMREAD_COLOR );

    if( image.empty() )
        return -1;
    
    /* Window size configuration */
    width   =   image.cols;
    height  =   image.rows;
    rel     =   ( float ) width / ( float ) height;
    if( width > MAX_WIDTH )
    {
        width   =   MAX_WIDTH;
        height  =   width / rel;
    }
    else if( height > MAX_HEIGHT )
    {
        height  =   MAX_HEIGHT;
        width   =   height * rel;
    }
     
    return 1;
}

string
ImageEditor::browse_file()
{
    char filename[ INPUT_SIZE ];
    FILE *file;
    uint16_t pos, i;
    string filename_str;

    filename[ 0 ] = '\0';
    file  = popen( "zenity --file-selection", "r" );
    fgets( filename, INPUT_SIZE, file );

    for( i = 0; i < INPUT_SIZE; i++ )
    {
        if( filename[ i ] == '\0' )
        {
            pos = i;
            break;
        } 
    }
    if( filename[ 0 ] == '\0' )
        filename_str    =   String( DEFAULT_IMAGE_PATH );
    else
        filename_str    =   String( filename ).substr( 0, pos - 1 );

    return samples::findFile( filename_str );
}

void
ImageEditor::rain_image()
{
    int drops, i, x, y;

    drops   =   height * width / rain_granularity;

    for( i = 0; i < drops; i++ )
    {
        x   =   rand() % ( width );
        y   =   rand() % ( height );

        drawMarker(	image,
                    Point( x, y ),
                    Scalar( 0, 0, 0 ),
                    MARKER_CROSS,
                    1 
        );
    }
}

void
ImageEditor::configure_settings()
{
    char value[ INPUT_SIZE ];
    char setting[ INPUT_SIZE ];
    FILE *file;
    long value_long;

    setting[ 0 ] = '\0';
    value[ 0 ]  = '\0';
    file  = popen( "./configure_settings.sh", "r" );

    fgets( value, INPUT_SIZE, file );
    fgets( setting, INPUT_SIZE, file );

    if( setting[ 0 ] == '\0' )   
        return;

    value_long  =   stol( value, NULL, 10 );  ;

    switch( setting[ 0 ] )
    {
        case 'b':
            bright_step = value_long;
            break;

        case 'c':
            contrast_step = value_long;
            break;

        case 'f':
            frame_anchor = value_long;
            break;

        case 'o':
            circle_anchor = value_long;
            break;

        case 'g':
            rain_granularity = value_long;
            break;
        
        default:
            break;
    }
}

int
ImageEditor::get_bright_step()
{
    return bright_step;
}

int
ImageEditor::get_contrast_step()
{
    return contrast_step;
}

int
ImageEditor::get_rain_granularity()
{
    return rain_granularity;
}

void
ImageEditor::add_frame()
{
    rectangle(  image,
                Point( 0, 0 ),
                Point( width, height ),
                Scalar( 0, 0, 0 ),
                frame_anchor,
                LINE_8,
                0 
    );
}

void
ImageEditor::add_circle()
{
    int radius;

    if( height < width )
        radius  =   height / 2;
    else
        radius  =   width / 2;

    radius  -=  circle_anchor / 2;

    circle(	image,
            Point( width / 2, height / 2 ),
            radius,
            Scalar( 0, 0, 0 ),
            circle_anchor,
            LINE_8,
            0 
    );
}

void
ImageEditor::modify_bright( int increase )
{
    image.convertTo(    image, 
                        -1, 
                        1, 
                        increase * bright_step 
    );
}

void
ImageEditor::modify_contrast( int increase )
{
    image.convertTo(    image, 
                        -1, 
                        increase * contrast_step, 
                        1
    );
}

void
ImageEditor::blure()
{
    blur( image, image, Size( kernel_size, kernel_size ) );
}

void
ImageEditor::to_gray_scale()
{
    image    =   imread( image_path, IMREAD_GRAYSCALE );
}

int
ImageEditor::show_image()
{
    namedWindow( WINDOW_NAME, WINDOW_NORMAL );
    resizeWindow( WINDOW_NAME, width, height );
    imshow( WINDOW_NAME, image );

    return waitKey( 0 );
}

void
ImageEditor::save_image()
{
    imwrite( DEFAULT_DESTINATION_PATH, image );
}