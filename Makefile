.SUFFIXES:
.SUFFIXES: .c .o

SRCDIR = src/main
TESTDIR = src/test
OBJDIR = build

# LDFLAGS, LDLIBS

include local.mk

OBJS = $(OBJDIR)/BlinkSignal_test.o $(OBJDIR)/BlinkSignal.o $(OBJDIR)/libarduino-mock.a $(OBJDIR)/libgtest.a $(OBJDIR)/libgmock.a

CPLUS_INCLUDE_PATH = $(GTEST_HOME_DIR)/googletest/include:$(GTEST_HOME_DIR)/googlemock/include:$(AMOCK_DIR)/include/arduino-mock:include

CXXFLAGS += -std=c++11 -stdlib=libc++ -DGTEST_USE_OWN_TR1_TUPLE=1

clean:
	rm -rf $(OBJDIR)/*

# run the tests
test: $(OBJDIR)/BlinkSignal_test
	$(OBJDIR)/BlinkSignal_test --gtest_output="xml:$(OBJDIR)/XML_Report.xml"

# link the tests
$(OBJDIR)/BlinkSignal_test: $(OBJS) $(OBJDIR)/gtest_main.o
	$(CXX) -o $@ $^

# compile the tests
$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(CPLUS_INCLUDE_PATH) -o $@ $<

# compile the source
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(CPLUS_INCLUDE_PATH) -o $@ $<

# create the gtest and gmock libraries
$(OBJDIR)/gtest-all.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(GTEST_HOME_DIR)/googletest/include -I$(GTEST_HOME_DIR)/googletest -c $(GTEST_HOME_DIR)/googletest/src/gtest-all.cc

$(OBJDIR)/gtest_main.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(GTEST_HOME_DIR)/googletest/include -c $(GTEST_HOME_DIR)/googletest/src/gtest_main.cc

$(OBJDIR)/libgtest.a: $(OBJDIR)/gtest-all.o
	ar -rv $(OBJDIR)/libgtest.a $(OBJDIR)/gtest-all.o

$(OBJDIR)/gmock-all.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(GTEST_HOME_DIR)/googlemock/include -I$(GTEST_HOME_DIR)/googlemock -c $(GTEST_HOME_DIR)/googlemock/src/gmock-all.cc

$(OBJDIR)/libgmock.a: $(OBJDIR)/gmock-all.o
	ar -rv $@ $<

# create the arduido-mock library
$(OBJDIR)/arduino-mock-all.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(GTEST_HOME_DIR)/googletest/include $(AMOCK_DIR)/src/ArduinoMockAll.cc

$(OBJDIR)/libarduino-mock.a: $(OBJDIR)/arduino-mock-all.o
	ar -rv $@ $<


	