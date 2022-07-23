//
// Created by cxf18 on 2022/7/14.
//

int main()
{
    Static_Sqlist Static_l;
    ListInit(&Static_l);
    ListInsert(&Static_l,100,1);
    ListInsert(&Static_l,112,2);
    ListInsert(&Static_l,113,3);
    ListInsert(&Static_l,114,4);
    ListInsert(&Static_l,115,5);
    ListInsert(&Static_l,116,6); // length = 6;在此处之前都是顺序插入
    ListInsert(&Static_l,102,2); // length = 7;在某一处插入,i后的元素向后移动.
    printf("insert\n");
    PrintList(&Static_l);
    ListDelete(&Static_l,2);
    printf("delete\n");
    PrintList(&Static_l);
    GetElem(&Static_l,5);
    LocateElem(&Static_l,115);

    Dynaminc_Sqlist Dynamic_l ;
    InitList(&Dynamic_l);
    IncreaseSize(&Dynamic_l,1);
    // 运行时进行动态扩展
    InsertList(&Dynamic_l,1,1);
    InsertList(&Dynamic_l,2,2);
    InsertList(&Dynamic_l,3,3);
    InsertList(&Dynamic_l,4,4);
    InsertList(&Dynamic_l,5,5);
    InsertList(&Dynamic_l,6,6);
    InsertList(&Dynamic_l,7,7);
    InsertList(&Dynamic_l,8,6);
    printf("insert\n");
    PrintList(&Dynamic_l);
    DeleteList(&Dynamic_l,6);
    printf("delete\n");
    PrintList(&Dynamic_l);
    GetElem(&Dynamic_l,6);
    LocateElem(&Dynamic_l,6);
    return 0;
}

