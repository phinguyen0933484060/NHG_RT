#include <iostream>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int count = 0;

void producer() {
    for (int i = 0; i < 10; i++) {
        std::unique_lock<std::mutex> lck(mtx);
        count++;
        std::cout << "Produced: " << count << std::endl;
        lck.unlock();
        cv.notify_all();
    }
}

void consumer() {
    for (int i = 0; i < 10; i++) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, []{ return count > 0; });
        count--;
        std::cout << "Consumed: " << count << std::endl;
        lck.unlock();
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);
    producer_thread.join();
    consumer_thread.join();
    return 0;
}
