//
// Created by Ziko on 07/06/2023.
//

#ifndef UNTITLED2_STRUCT_H
#define UNTITLED2_STRUCT_H

typedef struct Vehicle {
    char plateNr[20];
    char model[20];
    int year;
    char fType[20];
    double consumption;
    int seats;
    double dPrice;
    int count;
    struct Vehicle* next;
} Vehicle;

typedef struct Reservation {
    int reservationId;
    int date[3];
    char clientId[20];
    int nrDays;
    double tPrice;
    char plateNr[20];
    int diteDorezimi[3];
    struct Reservation* next;
} Reservation;

typedef struct Client {
    char clientId[20];
    char name [20];
    char surname[20];
    int passportId;
    char state[20];
    int phoneNr;
    struct Client* next;
} Client;

#endif //UNTITLED2_STRUCT_H
