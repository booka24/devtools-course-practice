// Copyright 2022 Abuyassen Albara


#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "include/Sequence.h"
#include "include/LIS_finder.h"

LISFinder::LISFinder(): message_("") {}

void LISFinder::help(const char * appname,
  const char * message) {
  message_ =
    std::string(message) +
    "This is the longest increasing subsequence finder application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <operation> <sequence length> <seqeunce>\n\n" +

    "Where all arguments are integers, " +
    "and <operation> is 1,2 or 3 where:\n\n" +
    "1 - To get the longest increasing subsequence\n" +
    "2 - To get the length of longest increasing subsequence\n" +
    "3 - To get the starting index of longest increasing subsequence\n";
}

bool LISFinder::validateNumberOfArguments(int argc,
  const char ** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 4) {
    help(argv[0], "ERROR: Should be 3 arguments or more.\n\n");
    return false;
  }
  return true;
}

int parseInt(const char * arg) {
  int value;
  try {
    value = std::stoi(arg);
  } catch (std::invalid_argument & e) {
    throw std::string("Wrong number format!");
  }
  return value;
}

int parseOperation(const char * arg) {
  int op;
  if (strcmp(arg, "1") == 0) {
    op = 1;
  } else if (strcmp(arg, "2") == 0) {
    op = 2;
  } else if (strcmp(arg, "3") == 0) {
    op = 3;
  } else {
    throw std::string("Wrong operation number provided!");
  }
  return op;
}

bool CheckCount(int argc, int length) {
  if (argc - 3 != length)
    throw std::string("Wrong length provided!");
  return true;
}

std::string LISFinder::operator()(int argc,
  const char ** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  int operation, length;
  std::vector < int > values;
  try {
    operation = parseOperation(argv[1]);
    length = parseInt(argv[2]);
    if (CheckCount(argc, length)) {
      for (int i = 3; i < argc; i++)
        values.push_back(parseInt(argv[i]));
    }
  } catch (std::string & str) {
    return str;
  }
  Sequence seq(length);
  seq.SetSequence(values);
  std::ostringstream stream;
  switch (operation) {
  case 1:
    values = seq.LIS();
    stream << "Longest increasing subsequence = { ";
    std::copy(values.begin(), values.end(),
      std::ostream_iterator < int > (stream, " "));
    stream << "}";
    break;
  case 2:
    stream << "Length of longest increasing subsequence  = " <<
      seq.GetLISlength();
    break;
  case 3:
    stream << "Starting index of longest increasing subsequence = " <<
      seq.GetStartingIndex();
    break;
  }

  message_ = stream.str();

  return message_;
}

