import os

mass_points = [("CH090",90),("CH100",100),("CH110",110),("CH120",120),("CH130",130),("CH140",140),("CH150",150)]
cuts_2b = [0.20,0.25,0.30,0.35,0.40,0.45,0.50,0.55]
cuts_3b = [0.2,0.25,0.30,0.35,0.40,0.45,0.50,0.55,0.60]


class Stat_Only_Expected():

    def __init__(self):
        pass

    def Text_to_Workspace(self):
        for mass_point in mass_points:
            for cut_2b in cuts_2b:
                for cut_3b in cuts_3b:
                    command_template = "text2workspace.py %s -P %s -o %s -m %i"
                    arg1 = "data_card/CHToCB_datacard_%s_%0.2f_%0.2f.txt"%(mass_point[0],cut_2b,cut_3b)
                    arg2 = "HiggsAnalysis.CombinedLimit.ChargedHiggs:brChargedHiggsCB"
                    arg3 = "workspace/mu_%d_%0.2f_%0.2f_stat.root"%(mass_point[1],cut_2b,cut_3b)
                    arg4 = mass_point[1]
                    command = command_template%(arg1,arg2,arg3,arg4)
                    #print(command)
                    os.system(command)

    def Combine(self):
        for mass_point in mass_points:
            for cut_2b in cuts_2b:
                for cut_3b in cuts_3b:
                    command_template = "combine %s --mass %d --name %s "
                    arg1 = "workspace/mu_%d_%.2f_%.2f_stat.root"%(mass_point[1],cut_2b,cut_3b)
                    arg2 = mass_point[1]
                    arg3 = "CHlimit_mu_%d_%.2f_%.2f"%(mass_point[1],cut_2b,cut_3b)
                    command = command_template%(arg1,arg2,arg3)
                    options = "-M AsymptoticLimits --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 "
                    command += options
                    pipe_line = "| tee combine/res_mu_%d_%.2f_%.2f_stat.out"%(mass_point[1],cut_2b,cut_3b)
                    command += pipe_line
                    #print(command)
                    os.system(command)

    def Tail(self):
        for mass_point in mass_points:
            for cut_2b in cuts_2b:
                for cut_3b in cuts_3b:
                    command = "tail res_mu_%d_%.2f_%.2f_stat.out | sed -e '9,10d' | "%(mass_point[1],cut_2b,cut_3b)
                    command += "awk {'print $5'} > dummy ; "
                    command += "sed '3i CLs' dummy > mu_%d_%.2f_%.2f_stat.out"%(mass_point[1],cut_2b,cut_3b)
                    #print(command)
                    os.system(command)


if __name__ == '__main__':
    s = Stat_Only_Expected()
    #s.Text_to_Workspace()
    #s.Combine()
    #s.Tail()
