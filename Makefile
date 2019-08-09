.SUFFIXES:
.SUFFIXES: .c .o

SRCDIR = src/main
TESTDIR = src/test
OBJDIR = build

# LDFLAGS, LDLIBS

include local.mk
ifndef GTEST_HOME_DIR
$(error GTEST_HOME_DIR is not set in local.mk)
endif
ifndef AMOCK_DIR
$(error AMOCK_DIR is not set in local.mk)
endif

include gtest.mk

OBJS = $(OBJDIR)/BlinkSignal_test.o $(OBJDIR)/BlinkSignal.o $(OBJDIR)/libarduino-mock.a $(OBJDIR)/libgtest.a $(OBJDIR)/libgmock.a

CPLUS_INCLUDE_PATH = -I$(GTEST_HOME_DIR)/googletest/include -I$(GTEST_HOME_DIR)/googlemock -I$(GTEST_HOME_DIR)/googlemock/include -I$(AMOCK_DIR)/include/arduino-mock -Iinclude

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
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(CPLUS_INCLUDE_PATH) -o $@ $<

# compile the source
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(CPLUS_INCLUDE_PATH) -o $@ $<

# create the arduino-mock library
$(OBJDIR)/arduino-mock-all.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(CPLUS_INCLUDE_PATH) $(AMOCK_DIR)/src/ArduinoMockAll.cc

$(OBJDIR)/libarduino-mock.a: $(OBJDIR)/arduino-mock-all.o
	ar -rv $@ $<


	