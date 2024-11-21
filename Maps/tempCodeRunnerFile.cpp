 //Calculate deviations larger than one and more than once
    int deletions = 0;
    for(const auto& [letter, freq] : letterFreq){
        if(freq >= mode + 2){
            cout<<"NO"<<endl;
        }
        if(freq < mode){
            cout<<"NO"<<endl;
        }
        if(freq == mode + 1){
            deletions ++;
        }

    }