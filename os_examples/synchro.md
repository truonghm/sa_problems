# Synchronisation

## Lock

Masking interrupt: A central processing unit (CPU) feature that allows the computer to ignore (mask) an interrupt request until the mask bit is disabled.

```C
typedef struct {
	int busy; // the lock taken or free
	proc_ctxt_list waitings; // waiting processes
} lock;

void InitLock(lock *l) {
	Mask();
	l->busy = false;
	initList(&(l->waitings));
	Unmask();
}
```

The code defines a lock data structure that can be used to synchronize access to a shared resource between multiple processes or threads.

The lock structure has two fields:

    busy - a boolean flag that indicates whether the lock is currently being held by some process or thread (true means the lock is held, false means it's free).

    waitings - a list of process contexts that are waiting to acquire the lock.

The InitLock function is used to initialize the lock. It takes a pointer to a lock structure and sets the busy field to false (indicating that the lock is initially free), and initializes an empty proc_ctxt_list for the waitings field.

The function also calls two other functions, Mask and Unmask, which allows the computer to ignore (mask) an interrupt request until the mask bit is disabled.

Overall, this code provides a basic framework for implementing a lock mechanism that can be used to protect shared resources from concurrent access by multiple processes or threads.

## Semaphores

- Tao 1 bien semaphore
- 
