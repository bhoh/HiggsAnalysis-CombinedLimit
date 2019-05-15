import os
import argparse
mass_points = [("CH090",90),("CH100",100),("CH110",110),("CH120",120),("CH130",130),("CH140",140),("CH150",150)]
cuts_2b =[0.00] #[0.00,0.35,0.55]
cuts_3b =[0.00] #[0.00,0.2,0.30,0.40,0.50,0.60]




class Get_Expected_Limit():

    def __init__(self,systOn="False",ch="Mu"):
        if systOn=="False":
            self.suffix = "stat_only"
        elif systOn=="True":
            self.suffix = "syst"
        else:
            raise RuntimeError("no such args: %s"%systOn)
        self.ch = ch #channel 'Mu' or 'El' or 'Comb'

    def combineCards(self):
        for mass_point in mass_points:
            for cut_2b in cuts_2b:
                for cut_3b in cuts_3b:
                    if cut_2b == 0.00 or cut_3b ==0.00:
                        if cut_2b != cut_3b:
                            continue
                    Name1 = "data_card/Mu_CHToCB_datacard_%s_%0.2f_%0.2f_%s.txt"%(mass_point[0],cut_2b,cut_3b,self.suffix)
                    Name2 = "data_card/El_CHToCB_datacard_%s_%0.2f_%0.2f_%s.txt"%(mass_point[0],cut_2b,cut_3b,self.suffix)
                    Out = "data_card/Comb_CHToCB_datacard_%s_%0.2f_%0.2f_%s.txt"%(mass_point[0],cut_2b,cut_3b,self.suffix)
                    cmd = 'python scripts/combineCards.py Name1=%s Name2=%s > %s'%(Name1,Name2,Out)
                    print(cmd)
                    os.system(cmd)
                    

    def Text_to_Workspace(self):
        for mass_point in mass_points:
            for cut_2b in cuts_2b:
                for cut_3b in cuts_3b:
                    if cut_2b == 0.00 or cut_3b ==0.00:
                        if cut_2b != cut_3b:
                            continue
                    #example:
                    #text2workspace.py CHToCB_datacard_CH090_0.35_0.40.txt -P HiggsAnalysis.CombinedLimit.ChargedHiggs:brChargedHiggsCB -o ../workspace/mu_90_0.35_0.40_stat.root -m 90
                    command_template = "text2workspace.py %s -P %s -o %s -m %i"
                    arg1 = "data_card/%s_CHToCB_datacard_%s_%0.2f_%0.2f_%s.txt"%(self.ch,mass_point[0],cut_2b,cut_3b,self.suffix)
                    arg2 = "HiggsAnalysis.CombinedLimit.ChargedHiggs:brChargedHiggsCB"
                    arg3 = "workspace/%s_%d_%0.2f_%0.2f_%s.root"%(self.ch,mass_point[1],cut_2b,cut_3b,self.suffix)
                    arg4 = mass_point[1]
                    command = command_template%(arg1,arg2,arg3,arg4)
                    #print(command)
                    os.system(command)

    def Combine(self):
        for mass_point in mass_points:
            for cut_2b in cuts_2b:
                for cut_3b in cuts_3b:
                    if cut_2b == 0.00 or cut_3b ==0.00:
                        if cut_2b != cut_3b:
                            continue
                    #example:
                    #combine ../workspace/mu_90_0.35_0.40_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 90 --name CHlimit_mu_90_0.35_0.40 | tee res_mu_90_0.35_0.40_stat.out
                    command_template = "combine %s --mass %d --name %s "
                    #FIXME
                    #command_template = "combine harvest install %s --mass %d --name %s "
                    arg1 = "workspace/%s_%d_%.2f_%.2f_%s.root"%(self.ch,mass_point[1],cut_2b,cut_3b,self.suffix)
                    arg2 = mass_point[1]
                    arg3 = "CHlimit_%s_%d_%.2f_%.2f_%s"%(self.ch,mass_point[1],cut_2b,cut_3b,self.suffix) 
                    options = "-M AsymptoticLimits --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 "
                    command = command_template%(arg1,arg2,arg3)
                    command += options
                    pipe_line = "| tee combine/res_%s_%d_%.2f_%.2f_%s.out"%(self.ch,mass_point[1],cut_2b,cut_3b,self.suffix)
                    command += pipe_line
                    #print(command)
                    os.system(command)
        os.system("mv higgsCombineCHlimit_%s_*.root output_root"%self.ch)

    def Tail(self):
        for mass_point in mass_points:
            for cut_2b in cuts_2b:
                for cut_3b in cuts_3b:
                    if cut_2b == 0.00 or cut_3b ==0.00:
                        if cut_2b != cut_3b:
                            continue
                    #example:
                    #tail res_mu_90_0.35_0.40_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_90_0.35_0.40_stat.out
                    command = "tail combine/res_%s_%d_%.2f_%.2f_%s.out | sed -e '9,10d' | "%(self.ch,mass_point[1],cut_2b,cut_3b,self.suffix)
                    command += "awk {'print $5'} > combine/dummy ; "
                    command += "sed '3i CLs' combine/dummy > combine/%s_%d_%.2f_%.2f_%s.out"%(self.ch,mass_point[1],cut_2b,cut_3b,self.suffix)
                    #print(command)
                    os.system(command)
        os.system("rm combine/dummy")


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-option',help="to turn on syst or not, False or True")
    parser.add_argument('-ch',help="Mu of El")
    parser.add_argument('-combine',help="combine El and Mu")
    args = parser.parse_args()
    option=args.option
    ch=args.ch
    s = Get_Expected_Limit(option,ch)
    if args.combine=="True":
        s.combineCards()
    else:
        s.Text_to_Workspace()
        s.Combine()
        s.Tail()
