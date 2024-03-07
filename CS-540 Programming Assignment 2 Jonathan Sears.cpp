// CS-540 Programming Assignment 2 Jonathan Sears.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>

using namespace std;

struct Process {
private:
    int processId;
    int lotteryNum;
 public:
    Process() = default;
    Process(int processId)
    {
        this->processId = processId;
        this->lotteryNum = rand() % 100 + 1;
    }
    int getID()
    {
        return processId;
    }
    int getLottery()
    {
        return lotteryNum;
    }
};

class Scheduler {
private:
    Process processList[3];
public:
    Process processListORDERED[3];
    Scheduler(Process Process1, Process Process2, Process Process3)
    {
        this->processList[0] = Process1;
        this->processList[1] = Process2;
        this->processList[2] = Process3;
        orderSchedule();
    }


    void orderSchedule()
    {
        if (processList[1].getLottery() > processList[0].getLottery() && processList[1].getLottery() > processList[2].getLottery())
        {
            if (processList[0].getLottery() > processList[2].getLottery())
            {
                this->processListORDERED[1] = processList[0];
                this->processListORDERED[2] = processList[2];
            }
            else
            {
                this->processListORDERED[1] = processList[2];
                this->processListORDERED[2] = processList[0];
            }
            this->processListORDERED[0] = processList[1];
        }
        else if(processList[0].getLottery() > processList[1].getLottery() && processList[0].getLottery() > processList[2].getLottery())
        {
            if (processList[1].getLottery() > processList[2].getLottery())
            {
                this->processListORDERED[1] = processList[1];
                this->processListORDERED[2] = processList[2];
            }
            else
            {
                this->processListORDERED[1] = processList[2];
                this->processListORDERED[2] = processList[1];
            }
            this->processListORDERED[0] = processList[0];
        }
        else
        {
            if (processList[0].getLottery() > processList[1].getLottery())
            {
                this->processListORDERED[1] = processList[0];
                this->processListORDERED[2] = processList[1];
            }
            else
            {
                this->processListORDERED[1] = processList[1];
                this->processListORDERED[2] = processList[0];
            }
            this->processListORDERED[0] = processList[2];
        }

    }

    void getSchedule()
    {
        cout << "Process " << processListORDERED[0].getID() << " goes first!" << endl;
    }
    
    
};




int main()
{
    Process Process1 = Process(1);
    Process Process2 = Process(2);
    Process Process3 = Process(3);
    
    Scheduler Schedule1 = Scheduler(Process1, Process2, Process3);
    Schedule1.getSchedule();


    
}


