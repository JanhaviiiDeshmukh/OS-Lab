#include <stdio.h>
#include <pthread.h>

int balance = 1000; 

void* balance_enquiry(void* arg) {
    printf("\n[Balance Enquiry] Current Balance: %d\n", balance);
    return NULL;
}

void* cash_withdrawal(void* arg) {
    int amount = 300;
    if (balance >= amount) {
        balance -= amount;
        printf("\n[Withdrawal] Amount Withdrawn: %d\n", amount);
        printf("[Withdrawal] Updated Balance: %d\n", balance);
    } else {
        printf("\n[Withdrawal] Insufficient Balance!\n");
    }
    return NULL;
}

void* deposit(void* arg) {
    int amount = 500;
    balance += amount;
    printf("\n[Deposit] Amount Deposited: %d\n", amount);
    printf("[Deposit] Updated Balance: %d\n", balance);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    printf("=== ATM Machine Simulation ===\n");

    // create threads
    pthread_create(&t1, NULL, balance_enquiry, NULL);
    pthread_create(&t2, NULL, cash_withdrawal, NULL);
    pthread_create(&t3, NULL, deposit, NULL);

    // wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("\nAll transactions done. Final Balance: %d\n", balance);
    return 0;
}
