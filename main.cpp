#include "image_editor.hpp"

int
main()
{
    string img_path; 
    Mat img, img_orig; 
    uint8_t k;
    uint32_t width, height;
    float rel;
    bool exit;

    /* ImageEditor creation */
    ImageEditor image_editor;

    /* Search file */
    image_search:
    img_path    =   samples::findFile( image_editor.browse_file() );

    /* Load image */
    img_orig    =   imread( img_path, IMREAD_COLOR );
    img_orig.convertTo( img, -1, 1, 0 );
    if( img.empty() )
    {
        cout << "Could not read the image: " << img_path << endl;
        return 1;
    }

    /* Window size configuration */
    width   =   img.cols;
    height  =   img.rows;
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

    /* Image edition loop */
    do
    {
        namedWindow( WINDOW_NAME, WINDOW_NORMAL );
        resizeWindow( WINDOW_NAME, width, height );
        imshow( WINDOW_NAME, img );

        k = waitKey( 0 ); 
        exit = false;

        switch ( k )
        {
            case 'a':
                image_editor.modify_contrast( &img, 1 );
                break;

            case 'b':
                image_editor.modify_contrast( &img, -1 );
                break;
            
            case 'c':
                image_editor.modify_bright( &img, 1 );
                break;

            case 'd':
                image_editor.modify_bright( &img, -1 );
                break;

            case 'e':
                image_editor.blure( &img );
                break;

            case 'i':
                image_editor.add_circle( &img, img.rows, img.cols );
                break;

            case 'k':
                image_editor.add_frame( &img, img.rows, img.cols );
                break;

            case 'l':
                image_editor.rain_image( &img, img.rows, img.cols );
                break;
            
            case 'm':
                image_editor.configure_settings();
                break;

            case 'o':
                goto image_search;
                
            case 'q':
                exit = true;
                break;

            case 'r':
                img_orig.convertTo( img, -1, 1, 0 );
                break;

            case 's':
                imwrite( DEFAULT_DESTINATION_PATH, img );
                break;

            default:
                break;
        }

    } while ( !exit );
    
    destroyAllWindows(); 

    return 0;
}