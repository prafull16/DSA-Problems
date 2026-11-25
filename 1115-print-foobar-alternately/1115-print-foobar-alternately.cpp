class FooBar {
private:
    int n;
    sem_t fooSem, barSem;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&fooSem, 0, 1);
        sem_init(&barSem, 0, 0);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&fooSem);
            printFoo();
            sem_post(&barSem);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&barSem);
            printBar();
            sem_post(&fooSem);
        }
    }
};