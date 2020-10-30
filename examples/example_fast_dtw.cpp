#include "DTW.h"
#include "FastDTW.h"
#include "EuclideanDistance.h"
#include <iostream>

// using namespace fastdtw;


double *sample1;
double *sample2;

std::vector<double> time_Series_1, time_Series_2;

void testDTW()
{
    fastdtw::TimeSeries<double,1> tsI;
    for (int i = 0; i<time_Series_1.size(); ++i) {
        tsI.addLast(i, fastdtw::TimeSeriesPoint<double,1>(sample1+i));
    }

    fastdtw::TimeSeries<double,1> tsJ;
    for (int i = 0;i<time_Series_2.size(); ++i)
    {
        tsJ.addLast(i, fastdtw::TimeSeriesPoint<double,1>(sample2+i));
    }

    fastdtw::TimeWarpInfo<double> info =  fastdtw::STRI::getWarpInfoBetween(tsI,tsJ,fastdtw::EuclideanDistance());
    printf("Warp Distance by DTW:%lf\n",info.getDistance());
    info.getPath()->print(std::cout);
}

void testFastDTW()
{
    fastdtw::TimeSeries<double,1> tsI;
    for (int i = 0; i<time_Series_1.size(); ++i) {
        tsI.addLast(i, fastdtw::TimeSeriesPoint<double,1>(sample1+i));
    }

    fastdtw::TimeSeries<double,1> tsJ;
    for (int i = 0;i<time_Series_2.size(); ++i)
    {
        tsJ.addLast(i, fastdtw::TimeSeriesPoint<double,1>(sample2+i));
    }

    fastdtw::TimeWarpInfo<double> info =  fastdtw::FAST::getWarpInfoBetween(tsI,tsJ,fastdtw::EuclideanDistance());
    printf("Warp Distance by DTW:%lf\n",info.getDistance());
    info.getPath()->print(std::cout);
}


int main(int argc , char ** argv)
{
    time_Series_1.push_back(0);
    time_Series_1.push_back(0);
    time_Series_1.push_back(0);
    time_Series_1.push_back(0);
    time_Series_1.push_back(1);
    time_Series_1.push_back(1);
    time_Series_1.push_back(2);
    time_Series_1.push_back(2);
    time_Series_1.push_back(3);
    time_Series_1.push_back(2);
    time_Series_1.push_back(1);
    time_Series_1.push_back(1);
    time_Series_1.push_back(1);
    time_Series_1.push_back(0);
    time_Series_1.push_back(0);
    time_Series_1.push_back(0);
    time_Series_1.push_back(0);

    sample1 = &time_Series_1[0];


    time_Series_2.push_back(0);
    time_Series_2.push_back(0);
    time_Series_2.push_back(1);
    time_Series_2.push_back(1);
    time_Series_2.push_back(2);
    time_Series_2.push_back(2);
    time_Series_2.push_back(3);
    time_Series_2.push_back(3);
    time_Series_2.push_back(3);
    time_Series_2.push_back(3);
    time_Series_2.push_back(2);

    sample2 = &time_Series_2[0];

    testDTW();
    testFastDTW();


    return 0;
}
