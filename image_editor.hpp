#ifndef _IMAGE_EDITOR_H
#define _IMAGE_EDITOR_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <unistd.h> // sacar

#include <iostream>

using namespace std;
using namespace cv;

#define DEFAULT_IMAGE_PATH              ( ( const char* )   "image.jpeg"        )
#define DEFAULT_DESTINATION_PATH        ( ( const char* )   "image_.jpeg"       )
#define INPUT_SIZE                      ( ( int ) 120                           )

#define WINDOW_NAME                     ( ( const char* )   "Display window"    )

#define DEFAULT_BRIGHT_STEP             ( ( double ) 10                         )
#define DEFAULT_CONTRAST_STEP           ( ( double ) 2                          )
#define DEFAULT_RAIN_GRANULARITY        ( ( int ) 32                            )
#define DEFAULT_FRAME_ANCHOR            ( ( int ) 35                            )
#define DEFAULT_CIRCLE_ANCHOR           ( ( int ) 10                            )
#define DEFAULT_KERNEL_SIZE             ( ( int ) 3                             )
#define DEFAULT_RED_STEP                ( ( int ) 5                             )

#define MAX_HEIGHT                      ( ( int ) 600                           )
#define MAX_WIDTH                       ( ( int ) 1200                          )

#define INCREASE_CONTRAST_KEY           ( ( char ) 'a'                          )
#define DECREASE_CONTRAST_KEY           ( ( char ) 'b'                          )
#define INCREASE_BRIGHT_KEY             ( ( char ) 'c'                          )
#define DECREASE_BRIGHT_KEY             ( ( char ) 'd'                          )
#define BLURE_IMAGE_KEY                 ( ( char ) 'e'                          )
#define ADD_CIRCLE_KEY                  ( ( char ) 'f'                          )
#define ADD_FRAME_KEY                   ( ( char ) 'g'                          )
#define RAIN_IMAGE_KEY                  ( ( char ) 'h'                          )
#define CONFIGURE_SETTINGS_KEY          ( ( char ) 'i'                          )
#define TO_GRAY_SCALE_KEY               ( ( char ) 'j'                          )
#define INCREASE_RED_KEY                ( ( char ) 'k'                          )
#define DECREASE_RED_KEY                ( ( char ) 'l'                          )
#define INCREASE_BLUE_KEY               ( ( char ) 'm'                          )
#define DECREASE_BLUE_KEY               ( ( char ) 'n'                          )
#define OPEN_IMAGE_KEY                  ( ( char ) 'o'                          )
#define EXIT_KEY                        ( ( char ) 'q'                          )
#define RELOAD_IMAGE_KEY                ( ( char ) 'r'                          )
#define SAVE_IMAGE_KEY                  ( ( char ) 's'                          )
#define INCREASE_GREEN_KEY              ( ( char ) 't'                          )
#define DECREASE_GREEN_KEY              ( ( char ) 'u'                          )


class ImageEditor
{       
    private:             
        Mat image;
        string image_path;
        int rain_granularity;
        int bright_step;
        int contrast_step;
        int frame_anchor;
        int circle_anchor;
        int kernel_size;
        int red_step;

    public:
        ImageEditor                     ( void                                  );
        int     setup                   ( string                                );
        void    configure_settings      ( void                                  );
        void    add_frame               ( void                                  );
        void    add_circle              ( void                                  );
        void    rain_image              ( void                                  );
        void    modify_bright           ( int                                   );
        void    modify_contrast         ( int                                   );
        void    blure_image             ( void                                  );
        void    to_gray_scale           ( void                                  );
        int     show_image              ( void                                  );
        void    save_image              ( void                                  );
        static string  browse_file      ( void                                  );
        void    set_reds                ( int                                   );
        void    set_blues               ( int                                   );
        void    set_greens              ( int                                   );
        void    modify_red              ( int                                   );
        void    modify_blue             ( int                                   );
        void    modify_green            ( int                                   );
};

#endif /* _IMAGE_EDITOR_H */