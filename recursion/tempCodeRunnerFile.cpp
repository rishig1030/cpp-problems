int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the sum: ";
    cin>>target;
    vector<int> v;
    f(0,0,v,target,arr,n);
