#include <stdio.h>
int main(void)
{
    /*  Хувьсагч зарлана */
    int cardBalance, rides, cost, totalCost, day, rechargeDay, warnLimit;
    int paid;                    /* хэдэн удаа төлөх */
    const char *status;          /* төлөв: текст */

    /*  Анхны утга */
    totalCost = 0;
    rechargeDay = 0;

    /*  Эхний үлдэгдэл: сөрөг бол дахин асууна */
    do {
    printf("Картны эхний үлдэгдэл: ");
    scanf("%d", &cardBalance);
    } while (cardBalance < 0);

    /*  Сануулгын хязгаар: сөрөг бол дахин асууна */
    do {
    printf("Сануулгын хязгаар: ");
    scanf("%d", &warnLimit);
    } while (warnLimit < 0);

    /*  Хүснэгтийн гарчиг */
    printf("\nӨдөр | Суудал | Төлбөр | Үлдэгдэл | Төлөв\n");

    /*  7 өдрийн давталт */
    for (day = 1; day <= 7; day++) {

        /* Суудлын тоо: сөрөг бол дахин асууна */
        do {
        printf("Өдөр %d суудлын тоо: ", day);
        scanf("%d", &rides);
        } while (rides < 0);

        /* Төлбөр: 4 суудал тутам 1 төлбөр */
        paid = (rides + 3) / 4; 
        cost = paid * 1000;

        /* Үлдэгдэл хасах, нийт зарцуулалт нэмэх */
        cardBalance = cardBalance - cost;
        totalCost = totalCost + cost;

        /*  Цэнэглэх өдөр олох */
        if (cardBalance < warnLimit && rechargeDay == 0) {
            rechargeDay = day;
        }

        /*  Төлөв */
        if (cardBalance < 0) {
            status = "Дутсан";
        } else if (cardBalance < warnLimit) {
            status = "Бага";
        } else {
            status = "Хангалттай";
        }

        /*  Хүснэгтийн мөр */
        printf("%4d | %6d | %6d | %8d | %s\n",
               day, rides, cost, cardBalance, status);
    }

    /*  Цэнэглэх өдөр */
    if (rechargeDay > 0) {
        printf("\nКартаа цэнэглэх өдөр: %d\n", rechargeDay);
    } else {
        printf("\nЭнэ 7 хоногт цэнэглэх шаардлагагүй\n");
    }

    /*  Нийт */
    printf("Нийт зарцуулсан: %d\n", totalCost);
    printf("Эцсийн үлдэгдэл: %d\n", cardBalance);

    return 0;
}