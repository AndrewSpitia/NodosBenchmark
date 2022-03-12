#!/usr/bin/perl
#####################################
# Date: 2022-03-03
# Course: Parallel Computing
# Topic laboratory design and execution automation (mean and deviation)
#####################################

$PATH=`pwd`; # get the current path
chomp($PATH); # remove the last character (\n)
$N =10; # number of processes
system "make clean"; # clean the previous compilation
system "make all"; # compile the program

$machineFile = "$PATH/machine.txt"; # machine file
open(MACHINE, '<', $machineFile) or die $!; # open the file to get the machine name
$machineName="";
while(<MACHINE>){
   $machineName= $_;
}
close($machineFile);
#Vector of executables
chomp($machineName);
@Executables=("Algorithm1","Algorithm2","Algorithm3");
@Dimension=("100","200","400","600","800","1000","1200","1400","1600","1800","2000","2200","2400","2600","2800","3000");
foreach $size (@Dimension){
	foreach $exe (@Executables){
		$File="results/results-$machineName.csv";
		#print"$File \n";
		open(FILE,">>",$File) or die "Could not open file $File";
		print FILE "Node,Load,Algorithm,Time\n";
		for($i=0;$i<$N;$i++){
			print FILE "$machineName,$size,$exe,";
			system "$PATH/$exe $size >> $File";
			print FILE "\n";
		}	
		close($File);
	}
	
}
