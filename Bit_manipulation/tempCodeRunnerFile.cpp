    int b = res;
    int count = 0;
    while (b != 0)
    {
        if (b & 1)
        {
            count++;
            break;
        }

        b = b >> 1;
    }
    cout<<count;