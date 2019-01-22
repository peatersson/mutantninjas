int lottery_example(int a, int b, int c, int d, int e){
    int correctNumbers = 0;
    if(a == 5){
        correctNumbers++;
    }
    if(b == 13){
        correctNumbers++;
    }
    if(c == 22){
        correctNumbers++;
    }
    if(d == 28){
        correctNumbers++;
    }
    if(e == 39){
        correctNumbers++;
    }
    return correctNumbers;
}
