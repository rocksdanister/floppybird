CXXFLAG = -std=c++11
LIBS = -lGL -lglut -lSOIL
floppybird: main.cpp frameupdate.cpp draw.cpp 
	$(CXX) $(CXXFLAG) main.cpp frameupdate.cpp draw.cpp -I. -o $@ $(LIBS) 
