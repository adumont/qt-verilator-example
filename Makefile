PROJECT := $(strip $(notdir $(patsubst %/,%,$(CURDIR))))

-include Design.mk

# TOP defaults to "top", can overwrite in Design.mk
TOP ?= top

.DEFAULT_GOAL := $(PROJECT)

$(PROJECT): $(PROJECT).mk obj_dir/verilated.o obj_dir/V$(TOP)__ALLcls.o obj_dir/V$(TOP)__ALLsup.o
	make -f $(PROJECT).mk

obj_dir/verilated.o  obj_dir/V$(TOP)__ALLcls.o  obj_dir/V$(TOP)__ALLsup.o: $(TOP).v
	verilator -Wall -cc $(TOP).v 
	make -C obj_dir/ -f V$(TOP).mk V$(TOP)__ALL.a verilated.o

$(PROJECT).mk: $(PROJECT).pro
	qmake $(PROJECT).pro -r -spec linux-g++-64 -o $(PROJECT).mk

clean:
	rm -rf obj_dir/
	rm -f $(PROJECT).mk $(PROJECT) *.o moc_*.cpp moc_*.h qrc_*.cpp ui_*.h

.PHONY: clean
