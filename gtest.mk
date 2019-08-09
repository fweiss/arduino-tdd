# create the gtest and gmock libraries
$(OBJDIR)/gtest-all.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(GTEST_HOME_DIR)/googletest/include -I$(GTEST_HOME_DIR)/googletest -c $(GTEST_HOME_DIR)/googletest/src/gtest-all.cc

$(OBJDIR)/gtest_main.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -I$(GTEST_HOME_DIR)/googletest/include -c $(GTEST_HOME_DIR)/googletest/src/gtest_main.cc

$(OBJDIR)/libgtest.a: $(OBJDIR)/gtest-all.o
	ar -rv $@ $<

$(OBJDIR)/gmock-all.o:
	$(CXX) -c -o $@ $< $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(CPLUS_INCLUDE_PATH) -c $(GTEST_HOME_DIR)/googlemock/src/gmock-all.cc

$(OBJDIR)/libgmock.a: $(OBJDIR)/gmock-all.o
	ar -rv $@ $<
