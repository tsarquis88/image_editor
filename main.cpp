#include "image_editor.hpp"

int
main()
{
    string img_path; 
    uint8_t k;
    bool exit;
    ImageEditor image_editor;

    /* ImageEditor setup */
    image_setup:
    img_path    =   ImageEditor::browse_file();
    if( image_editor.setup( img_path ) == -1 )
    {
        cout << "Could not read the image:" << img_path << endl;
        return 1;
    }

    /* Image edition loop */
    do
    {
        k       =   image_editor.show_image();
        exit    =   false;

        switch ( k )
        {
            case 'a':
                image_editor.modify_contrast( 1 );
                break;

            case 'b':
                image_editor.modify_contrast( -1 );
                break;
            
            case 'c':
                image_editor.modify_bright( 1 );
                break;

            case 'd':
                image_editor.modify_bright( -1 );
                break;

            case 'e':
                image_editor.blure();
                break;

            case 'f':
                image_editor.add_circle();
                break;

            case 'g':
                image_editor.add_frame();
                break;

            case 'h':
                image_editor.rain_image();
                break;
            
            case 'i':
                image_editor.configure_settings();
                break;

            case 'j':
                image_editor.to_gray_scale();
                break;

            case 'o':
                goto image_setup;
                
            case 'q':
                exit = true;
                break;

            case 'r':
                image_editor.setup( img_path );
                break;

            case 's':
                image_editor.save_image();
                break;

            default:
                break;
        }

    } while ( !exit );
    
    destroyAllWindows(); 

    return 0;
}