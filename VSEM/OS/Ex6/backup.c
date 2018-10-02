for(i=1;i<n;i++)
    {
        printf("%s\t",temp[i].name);
        waiting[i] = (temp[i-1].burst+waiting[i-1]);
    }
    
    for(i=0;i<n;i++)
    {
        totWait += waiting[i] - temp[i].arrival;
        totTround += waiting[i] + temp[i].burst - temp[i].arrival;
    }
