//
// Created by Ziko on 07/06/2023.
//

#ifndef UNTITLED2_JUSRA_H
#define UNTITLED2_JUSRA_H



void displayAllVehicles(Vehicle *head){
    if (head==NULL){
        printf("No vehicles:(!\n");
        return;}
    Vehicle *curr=NULL;
    curr=head;
    int i=0;
    while (curr!=NULL)
    {   printf("Info nr %d\n",i+1);
        printf("............\n");

        printf("Plate Number- %s\n", curr->plateNr);
        printf("Model- %s\n", curr->model);
        printf("Year- %d\n", curr->year);
        printf("Fuel Type- %s\n", curr->fType);
        printf("Consumption- %.1f\n", curr->consumption);
        printf("Nr of Seats- %d\n", curr->seats);
        printf("Daily Price- %.2f\n", curr->dPrice);
        printf("\n");
        curr=curr->next;
        i++;
    }
}
//        printf("|  15. Display all reservations                                   |\n");
void displayAllReservations(Reservation *head){
    if (head==NULL){
        printf("No reservation:(!\n");
        return;}
    Reservation *curr=NULL;
    curr=head;
    int i=0;
    while (curr!=NULL)
    {   printf("Info nr %d\n",i+1);
        printf("............\n");

        printf("Reservation ID- %d\n", curr->reservationId);
        printf( "Date-");
        for (int j = 0; j < 3; j++) {
            printf( "%d/", curr->date[j]);
        }
        printf("Client ID- %s\n", curr->clientId);
        printf("Nr of Days- %d\n", curr->nrDays);
        printf( "Plate Nr- %s\n", curr->plateNr);
        printf("Total Price- %.2f\n", curr->tPrice);
        printf("Booking End Date-");
        for (int j = 0; j < 3; j++) {
            printf( " %d/", curr->diteDorezimi[j]);
        }
        printf("\n");
        curr=curr->next;
        i++;
    }
}
void removeVehicle(Vehicle**head) {
    if (*head == NULL) {
        printf("No vehicles.\n");
        return;
    }

    char plateNumber[20];
    printf("Enter the license plate number: ");
    scanf("%s", plateNumber);

    Vehicle* current ;
    current=*head;
    Vehicle* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->plateNr, plateNumber) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            printf("Vehicle removed successfully.\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Vehicle missing.\n");
}


#endif //UNTITLED2_JUSRA_H
