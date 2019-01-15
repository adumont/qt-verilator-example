$ rm -rf obj_dir/
$ verilator -Wall -cc top.v 
$ make -C obj_dir/ -f Vtop.mk Vtop__ALL.a verilated.o

build with:

g++ -Wall -m64 -o timer ../timer/obj_dir/*.o main.o mainwindow.o moc_mainwindow.o -L/usr/X11R6/lib64 -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread


