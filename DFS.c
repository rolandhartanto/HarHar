#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int destination;
int startpoint;
int found = 0;
int tipu[15];
int arrjalan[15];
int idxarrjalan;

void intro()
{
	// inisialisasi array kosong
	// maju cari biru
	setMotorSpeed(leftMotor,50);
  setMotorSpeed(rightMotor,50);
  while(true)
  {
  	if(getColorName(colorSensor) == colorBlue)
  	{
  		break;
  	}
	}
  while(true)
  {
  	if(getColorName(colorSensor) == colorBlack)
  	{
  		break;
  	}
	}
	forward(0.3);
}

void FindGreen()
{
	while(true)
  {
  	 // sensor sees light:
    if (getColorName(colorSensor) == colorBlack){
    	motor[leftMotor]  = 55;
    	motor[rightMotor] = -15;
  	}
    else{
    	if(getColorName(colorSensor) == colorWhite){
      // counter-steer right:
      	motor[leftMotor]  = -15;
     		motor[rightMotor] = 55;
			}
			else if((getColorName(colorSensor) == colorBlue)||(getColorName(colorSensor) == colorGreen)||(getColorName(colorSensor) == colorYellow)||(getColorName(colorSensor) == colorRed)){
    		motor[leftMotor] = 0;
    		motor[rightMotor] = 0;
    		break;
    	}
    }
  }
}


void putar(int *adakiri, int *adakanan, int *adatengah){
  int kiri, kanan, tengah;
	kiri = 0;
  tengah = 0;
  kanan = 0;

  int jumlahcabang = 0;
  // asumsi semua 90 derajat
	backward(0.3);
	int g1 = getGyroDegrees(gyroSensor);
	while (getGyroDegrees(gyroSensor) < (g1 + 90)){
		setMotorSpeed(leftMotor,20);
		setMotorSpeed(rightMotor,-20);
	}
	g1 = getGyroDegrees(gyroSensor);
	int g2 = g1;
	while(g2 > (g1-360)){
		// tambahin range pencarian
		g2 = getGyroDegrees(gyroSensor);
		if((getGyroDegrees(gyroSensor) < (g1 - 40))&&(getGyroDegrees(gyroSensor) > (g1 - 90))){
			if(getColorName(colorSensor) == colorBlack){
				kanan = 1;
			}
		}
		if((getGyroDegrees(gyroSensor) < (g1 - 140))&&(getGyroDegrees(gyroSensor) > (g1 - 180))){
			if(getColorName(colorSensor) == colorBlack){
				tengah = 1;
			}
		}
		if((getGyroDegrees(gyroSensor) < (g1 - 200))&&(getGyroDegrees(gyroSensor) > (g1 - 280))){
			if(getColorName(colorSensor) == colorBlack){
				kiri = 1;
			}
		}
		setMotorSpeed(leftMotor,20);
		setMotorSpeed(rightMotor,50);
	}
	g1 = getGyroDegrees(gyroSensor);
	jumlahcabang = kiri + kanan + tengah;
	*adakiri = kiri;
	*adakanan = kanan;
	*adatengah = tengah;
	while (getGyroDegrees(gyroSensor) > (g1 - 90)){
		setMotorSpeed(leftMotor,-20);
		setMotorSpeed(rightMotor,20);
	}
}

void turn1(){
	// posisi sudah di backward
	int g1 = getGyroDegrees(gyroSensor);
	while (getGyroDegrees(gyroSensor) > (g1 - 50)){
		setMotorSpeed(leftMotor,-20);
		setMotorSpeed(rightMotor,20);
	}
	while (getColorName(colorSensor) != colorWhite){
		setMotorSpeed(leftMotor,50);
		setMotorSpeed(rightMotor,25);
	}
	// warna putih
	while (getColorName(colorSensor) != colorBlack){
		setMotorSpeed(leftMotor,50);
		setMotorSpeed(rightMotor,25);
	}
	while (getColorName(colorSensor) != colorWhite){
		setMotorSpeed(leftMotor,50);
		setMotorSpeed(rightMotor,25);
	}
	// set break
	setMotorSpeed(leftMotor,0);
	setMotorSpeed(rightMotor,0);
}

void turn2(){
	// posisi sudah di backward
	int g1 = getGyroDegrees(gyroSensor);
	while (getGyroDegrees(gyroSensor) > (g1 - 50)){
		setMotorSpeed(leftMotor,-20);
		setMotorSpeed(rightMotor,20);
	}
	while (getColorName(colorSensor) != colorWhite){
		setMotorSpeed(leftMotor,50);
		setMotorSpeed(rightMotor,25);
	}
	// warna putih
	while (getColorName(colorSensor) != colorBlack){
		setMotorSpeed(leftMotor,50);
		setMotorSpeed(rightMotor,25);
	}
	while (getColorName(colorSensor) != colorWhite){
		setMotorSpeed(leftMotor,50);
		setMotorSpeed(rightMotor,25);
	}
	while (getColorName(colorSensor) != colorBlack){
		setMotorSpeed(leftMotor,50);
		setMotorSpeed(rightMotor,25);
	}
	// set break
	setMotorSpeed(leftMotor,0);
	setMotorSpeed(rightMotor,0);
}

void turn3(){
	// posisi sudah di backward
	int g1 = getGyroDegrees(gyroSensor);
	while (getGyroDegrees(gyroSensor) < (g1 + 90)){
		setMotorSpeed(leftMotor,20);
		setMotorSpeed(rightMotor,-20);
	}
	while (getColorName(colorSensor) != colorWhite){
		setMotorSpeed(leftMotor,25);
		setMotorSpeed(rightMotor,50);
	}
	// warna putih
	while (getColorName(colorSensor) != colorBlack){
		setMotorSpeed(leftMotor,25);
		setMotorSpeed(rightMotor,50);
	}
	// set break
	setMotorSpeed(leftMotor,0);
	setMotorSpeed(rightMotor,0);
}

void introtipu(){
	int i;
	for(i=1;i<15;i++){
		tipu[i] = 99;
	}
	intro();
}

void putar180(){
	int g1 = getGyroDegrees(gyroSensor);
	while (getGyroDegrees(gyroSensor) > (g1 - 180)){
		setMotorSpeed(leftMotor,-50);
		setMotorSpeed(rightMotor,50);
	}
}

void pulangtipu(){
	putar180();
	int i = destination - 1;
	while(true){
		while(tipu[i] <= 0){
			i--;
		}
		// i adalah destination
		startpoint = destination;
		destination = i;
		FindGreen();
		if (getColorName(colorSensor) != colorBlue){
			if (tipu[i] == 1){
				turn1();
			}
			else if (tipu[i] == 2){
				turn1();
				// buat turn2()
			}
			else if (tipu[i] == 3){
				turn3();
			}
		}
		else{
			break;
		}
	}
}

void DFStipu(){
	// jika hijau
	FindGreen();
	if (getColorName(colorSensor) == colorGreen){
		int kiri, kanan, tengah, banyakcabang, temp, temp2, temp3, temp4;
		putar(&kiri, &kanan, &tengah);
		//dapat angka banyaknya cabang
		banyakcabang = kiri + kanan + tengah;
		tipu[destination] = banyakcabang;
		// cari tempat kosong, assign sebagai tempat tujuan
		temp = startpoint;
		temp2 = destination;
		startpoint = destination;
		while(tipu[destination] != 99){
			destination++;
		}
		// destination adalah nomor terkecil yang kosong
		// isi sesuai banyaknya cabang dengan -1
		int i;
		for(i=destination; i< destination+banyakcabang; i++){
			tipu[i] = -1;
		}
		turn1();
		temp3 = startpoint;
		temp4 = destination;
		for(i=1;i<=banyakcabang;i++){
			// belok kiri
			if (found == 0){
				startpoint = temp3;
				destination = temp4 + i - 1;
				DFStipu();
			}
			else{
				break;
			}
		}
		if (found == 0){
			startpoint = temp2;
			destination = temp;
			FindGreen();
			backward(0.5);
			turn1();
		}
		else{
			arrjalan[idxarrjalan] = destination;
			idxarrjalan++;
			if (tipu[destination] == 1){
				turn1();
			}else if (tipu[destination] == 2){
				turn2();
			}else if (tipu[destination] == 3){
				turn3();
			}
			startpoint = destination;
			destination--;
			while(tipu[destination] <= 0){
				destination--;
			}
			FindGreen();
		}
	}
	// jika merah
	else 	if (getColorName(colorSensor) == colorRed){
		// putar 180 derajat
		tipu[destination] = 0;
		putar180();
		int temp;
		temp = startpoint;
		startpoint = destination;
		destination = temp;
		// tuker dest sama startpoint, tipu[destination] = tipu[destination] - 1
		tipu[destination] = tipu[destination] - 1;
		FindGreen();
		turn1();
		temp = startpoint;
		startpoint = destination;
		destination = temp;
	}
	// jika kuning
	else if (getColorName(colorSensor) == colorYellow){
		found = 1;
		displayTextLine(1,"Api telah dipadamkan");
		tipu[destination] = 0;
		putar180();
		int temp;
		temp = startpoint;
		startpoint = destination;
		destination = temp;
		// tuker dest sama startpoint, tipu[destination] = tipu[destination] - 1
		tipu[destination] = tipu[destination] - 1;
		FindGreen();
	}
}

task main()
{
	displayTextLine(1,"DFS");
	introtipu();
	startpoint = 0;
	destination = 1;
	idxarrjalan = 0;
	DFStipu();
	int i;
	for (i=0; i<idxarrjalan; i++){
		if (tipu[arrjalan[i]] == 1){
			displayTextLine(idxarrjalan-i,"1");
		}else if (tipu[arrjalan[i]] == 2){
			displayTextLine(idxarrjalan-i,"2");
		}else if (tipu[arrjalan[i]] == 3){
			displayTextLine(idxarrjalan-i,"3");
		}
	}
	while(true)
	{
		setMotorSpeed(leftMotor,0);
		setMotorSpeed(rightMotor,0);
		setMotorSpeed(armMotor,50);
		sleep(1000);
		setMotorSpeed(armMotor,-50);
		sleep(1000);
	}
}
