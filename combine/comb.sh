#!/bin/bash


combine ../workspace/mu_90_0.35_0.40_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 90 --name CHlimit_mu_90_0.35_0.40 | tee res_mu_90_0.35_0.40_stat.out
combine ../workspace/mu_90_0.35_0.60_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 90 --name CHlimit_mu_90_0.35_0.60 | tee res_mu_90_0.35_0.60_stat.out

combine ../workspace/mu_100_0.35_0.40_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 100 --name CHlimit_mu_100_0.35_0.40 | tee res_mu_100_0.35_0.40_stat.out
combine ../workspace/mu_100_0.35_0.60_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 100 --name CHlimit_mu_100_0.35_0.60 | tee res_mu_100_0.35_0.60_stat.out

combine ../workspace/mu_110_0.35_0.40_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 110 --name CHlimit_mu_110_0.35_0.40 | tee res_mu_110_0.35_0.40_stat.out
combine ../workspace/mu_110_0.35_0.60_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 110 --name CHlimit_mu_110_0.35_0.60 | tee res_mu_110_0.35_0.60_stat.out

combine ../workspace/mu_120_0.35_0.40_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 120 --name CHlimit_mu_120_0.35_0.40 | tee res_mu_120_0.35_0.40_stat.out
combine ../workspace/mu_120_0.35_0.60_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 120 --name CHlimit_mu_120_0.35_0.60 | tee res_mu_120_0.35_0.60_stat.out

combine ../workspace/mu_130_0.35_0.40_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 130 --name CHlimit_mu_130_0.35_0.40 | tee res_mu_130_0.35_0.40_stat.out
combine ../workspace/mu_130_0.35_0.60_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 130 --name CHlimit_mu_130_0.35_0.60 | tee res_mu_130_0.35_0.60_stat.out

combine ../workspace/mu_140_0.35_0.40_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 140 --name CHlimit_mu_140_0.35_0.40 | tee res_mu_140_0.35_0.40_stat.out
combine ../workspace/mu_140_0.35_0.60_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 140 --name CHlimit_mu_140_0.35_0.60 | tee res_mu_140_0.35_0.60_stat.out

combine ../workspace/mu_150_0.35_0.40_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 150 --name CHlimit_mu_150_0.35_0.40 | tee res_mu_150_0.35_0.40_stat.out
combine ../workspace/mu_150_0.35_0.60_stat.root -M AsymptoticLimits  --cminDefaultMinimizerType Minuit2 --rAbsAcc 0.000001 --mass 150 --name CHlimit_mu_150_0.35_0.60 | tee res_mu_150_0.35_0.60_stat.out
