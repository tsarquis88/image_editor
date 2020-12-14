#ifndef _IMAGE_EDITOR_H
#define _IMAGE_EDITOR_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

#define DEFAULT_IMAGE_PATH              ( ( const char* )   "image.jpeg"        )
#define DEFAULT_DESTINATION_PATH        ( ( const char* )   "image_.jpeg"       )
#define INPUT_SIZE                      ( ( uint32_t ) 120                      )

#define WINDOW_NAME                     ( ( const char* )   "Display window"    )

#define DEFAULT_BRIGHT_STEP             ( ( double ) 10                         )
#define DEFAULT_CONTRAST_STEP           ( ( double ) 2                          )
#define DEFAULT_RAIN_GRANULARITY        ( ( int ) 32                            )
#define DEFAULT_FRAME_ANCHOR            ( ( int ) 35                            )
#define DEFAULT_CIRCLE_ANCHOR           ( ( int ) 10                            )
#define DEFAULT_KERNEL_SIZE             ( ( uint8_t ) 3                         )

#define MAX_HEIGHT                      ( ( int ) 600                           )
#define MAX_WIDTH                       ( ( int ) 1200                          )

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
        int height;
        int width;
        float rel;

    public:
        ImageEditor                     ( void                                  );
        int     setup                   ( string                                );
        void    configure_settings      ( void                                  );
        int     get_bright_step         ( void                                  );
        int     get_contrast_step       ( void                                  );
        int     get_rain_granularity    ( void                                  );
        int     get_frame_anchor        ( void                                  );
        int     get_circle_anchor       ( void                                  );
        int     get_kernel_size         ( void                                  );
        void    add_frame               ( void                                  );
        void    add_circle              ( void                                  );
        void    rain_image              ( void                                  );
        void    modify_bright           ( int                                   );
        void    modify_contrast         ( int                                   );
        void    blure                   (                                       );
        void    to_gray_scale           (                                       );
        int     show_image              ( void                                  );
        void    save_image              ( void                                  );
        static string  browse_file      ( void                                  );
};

#endif /* _IMAGE_EDITOR_H */