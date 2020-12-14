CC := g++
CCFLAG := -std=c++17 -Wall -Werror -pedantic -Wextra -Wconversion 
CCFLAG := -std=c++17 -Wall -pedantic -Wextra -g
CPPFLAG = --enable=all --suppress=missingIncludeSystem -q
INCLUDE := -I/usr/include/opencv4
LINKS := -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_flann
LINKS := -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

make:
	$(CC) $(CCFLAG) $(INCLUDE) $(LINKS)  -o image_editor.o image_editor.cpp main.cpp