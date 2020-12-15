#include "image_editor.hpp"

// TODO config color step

int
main()
{
    string img_path; 
    uint8_t k;
    bool exit;
    ImageEditor image_editor;

    /* Image browsing */
    image_setup:
    try
    {
        img_path    =   ImageEditor::browse_file();
    }
    catch( Exception& e )
    {
        const char* err_msg = e.what();
        cout << "Something went wrong: " << err_msg << endl;
        return 1;
    }
    
    /* Image load */
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
            case INCREASE_CONTRAST_KEY:
                image_editor.modify_contrast( 1 );
                break;

            case DECREASE_CONTRAST_KEY:
                image_editor.modify_contrast( -1 );
                break;
            
            case INCREASE_BRIGHT_KEY:
                image_editor.modify_bright( 1 );
                break;

            case DECREASE_BRIGHT_KEY:
                image_editor.modify_bright( -1 );
                break;

            case BLURE_IMAGE_KEY:
                image_editor.blure_image();
                break;

            case ADD_CIRCLE_KEY:
                image_editor.add_circle();
                break;

            case ADD_FRAME_KEY:
                image_editor.add_frame();
                break;

            case RAIN_IMAGE_KEY:
                image_editor.rain_image();
                break;
            
            case CONFIGURE_SETTINGS_KEY:
                image_editor.configure_settings();
                break;

            case TO_GRAY_SCALE_KEY:
                image_editor.to_gray_scale();
                break;

            case OPEN_IMAGE_KEY:
                goto image_setup;
                
            case EXIT_KEY:
                exit = true;
                break;

            case RELOAD_IMAGE_KEY:
                image_editor.setup( img_path );
                break;

            case SAVE_IMAGE_KEY:
                image_editor.save_image();
                break;

            case INCREASE_RED_KEY:
                image_editor.modify_red( 1 );
                break;

            case DECREASE_RED_KEY:
                image_editor.modify_red( -1 );
                break;

            case INCREASE_BLUE_KEY:
                image_editor.modify_blue( 1 );
                break;

            case DECREASE_BLUE_KEY:
                image_editor.modify_blue( -1 );
                break;

            case INCREASE_GREEN_KEY:
                image_editor.modify_green( 1 );
                break;

            case DECREASE_GREEN_KEY:
                image_editor.modify_green( -1 );
                break;

            default:
                break;
        }

    } while ( !exit );
    
    destroyAllWindows(); 

    return 0;
}