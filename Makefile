timer: timer.mk obj_dir/verilated.o obj_dir/Vtop__ALLcls.o obj_dir/Vtop__ALLsup.o
	make -f timer.mk

obj_dir/verilated.o  obj_dir/Vtop__ALLcls.o  obj_dir/Vtop__ALLsup.o: top.v
	verilator -Wall -cc top.v 
	make -C obj_dir/ -f Vtop.mk Vtop__ALL.a verilated.o

timer.mk: timer.pro
	qmake timer.pro -r -spec linux-g++-64 -o timer.mk

clean:
	rm -rf obj_dir/
	rm -f timer.mk timer *.o
