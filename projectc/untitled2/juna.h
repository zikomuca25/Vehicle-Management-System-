//
// Created by Ziko on 07/06/2023.
//

#ifndef UNTITLED2_JUNA_H
#define UNTITLED2_JUNA_H



void addVehicle(Vehicle **head) {
    Vehicle *newVehicle,*curr,*prev;
    newVehicle = (Vehicle *) malloc(sizeof(Vehicle));

    printf("Plate Nr: ");
    scanf("%s", newVehicle->plateNr);
    printf("Year: ");
    scanf("%d", &(newVehicle->year));
    printf("Model: ");
    scanf("%s", newVehicle->model);
    printf("Fuel Type: ");
    scanf("%s", newVehicle->fType);
    printf("Consumption ");
    scanf("%lf", &(newVehicle->consumption));
    printf("Nr of Seats ");
    scanf("%d", &(newVehicle->seats));
    printf("Daily Price");
    scanf("%lf", &(newVehicle->dPrice));

    newVehicle->next = NULL;
    curr = *head;
    while ( curr != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        prev->next = newVehicle;
        newVehicle->next = NULL;
    }
    printf("Vehicle added successfully.\n");
}
void displayTop3ReservedVehicles(Vehicle *headv,Reservation *headr) {
    // Count the number of reservations for each vehicle
    Vehicle* current ;
    current=headv;
    Reservation *reservationCurrent = NULL;
    int reservationCount;

    while (current != NULL) {
        reservationCount = 0;
        reservationCurrent = headr;
        while (reservationCurrent != NULL) {
            if (strcmp(reservationCurrent->plateNr,current->plateNr)==0) {
                reservationCount++;
            }
            reservationCurrent = reservationCurrent->next;
        }
        current->count = reservationCount;
        current = current->next;
    }

    // Sort the vehicles by rental count
    for (int i = 0; i < 3; i++) {
        Vehicle* max = headv;
        current = headv->next;
        while (current != NULL) {
            if (current->count > max->count) {
                max = current;
            }
            current = current->next;
        }
        if (max->count > 0) {
            printf("Vehicle %d:\n", i + 1);
            printf("Plate Nr: %s\n", max->plateNr);
            printf("Year: %d\n", max->year);
            printf("Model: %s\n", max->model);
            printf("Fuel Type: %s\n", max->fType);
            printf("Consumption: %.2f\n", max->consumption);
            printf("Nr of Seats: %d\n", max->seats);
            printf("Daily Price: %.2f\n", max->dPrice);
            printf("Nr of Reservations: %d\n", max->count);
            printf("\n");
            max->count = 0; // Reset rental count to avoid duplicate display
        } else {
            break; // No more vehicles with rentals
        }
    }
}
void displayClientsWithMoreThan3Rentals(Client *headc,Reservation*headr) {
    Client *currentClient;
    currentClient = headc;
    Reservation *currentReservation;
    int rentalCount;
    while (currentClient != NULL) {
        rentalCount = 0;
        currentReservation = headr;
        while (currentReservation != NULL) {

            if (strcmp(currentReservation->clientId, currentClient->clientId) == 0) {
                rentalCount++;
            }
            currentReservation = currentReservation->next;
        }
        if (rentalCount >= 3) {
            printf("Client ID: %s\n", currentClient->clientId);
            printf("Name: %s %s\n", currentClient->name, currentClient->surname);
            printf("\n");
        } else {
            printf("No client has more than 3 reservation!");
        }

        currentClient = currentClient->next;
    }
}
#endif //UNTITLED2_JUNA_H
