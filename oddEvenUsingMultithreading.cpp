// Demonstrating a program, printing a n numbers odd and even using the power of multithreading

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mu;
std::condition_variable cond;
int count = 1;

void PrintOdd()
{
    for(; count < 100;)
    {
        std::unique_lock<std::mutex> locker(mu);    //Acquires a unique lock on the mu mutex, ensuring exclusive access to shared data.
        cond.wait(locker,[](){ return (count%2 == 1); });    //Waits on the cond condition variable until the predicate (count%2 == 1) becomes true.
        std::cout << "From Odd:    " << count << std::endl;
        count++;
        locker.unlock();    //Releases the lock on the mu mutex, allowing other threads to access shared data.
        cond.notify_all();    //Notifies all threads waiting on the cond condition variable, potentially waking them up.
    }

}

void PrintEven()
{
    for(; count < 100;)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker,[](){ return (count%2 == 0); });
        std::cout << "From Even: " << count << std::endl;
        count++;
        locker.unlock();
        cond.notify_all();
    }
}

int main()
{
    std::thread t1(PrintOdd);
    std::thread t2(PrintEven);
    t1.join();
    t2.join();
    return 0;
}
