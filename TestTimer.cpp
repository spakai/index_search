#include "TestTimer.h"

#include <iostream>

using namespace std;

TestTimer::TestTimer(const string& text,int transactions) 
   : Start{chrono::system_clock::now()} 
   , Text{text}
   , Transactions(transactions) {}

TestTimer::~TestTimer() {
   Stop = chrono::system_clock::now();
   Elapsed = chrono::duration_cast<chrono::microseconds>(Stop - Start);
   cout << endl <<
      Text << " average time = " << Elapsed.count() * 0.001 / Transactions << "ms" << endl;
}

