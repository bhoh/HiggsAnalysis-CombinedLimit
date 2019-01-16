#!/bin/bash

tail res_mu_90_0.35_0.40_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_90_0.35_0.40_stat.out
tail res_mu_90_0.35_0.60_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_90_0.35_0.60_stat.out

tail res_mu_100_0.35_0.40_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_100_0.35_0.40_stat.out
tail res_mu_100_0.35_0.60_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_100_0.35_0.60_stat.out

tail res_mu_110_0.35_0.40_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_110_0.35_0.40_stat.out
tail res_mu_110_0.35_0.60_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_110_0.35_0.60_stat.out

tail res_mu_120_0.35_0.40_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_120_0.35_0.40_stat.out
tail res_mu_120_0.35_0.60_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_120_0.35_0.60_stat.out

tail res_mu_130_0.35_0.40_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_130_0.35_0.40_stat.out
tail res_mu_130_0.35_0.60_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_130_0.35_0.60_stat.out

tail res_mu_140_0.35_0.40_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_140_0.35_0.40_stat.out
tail res_mu_140_0.35_0.60_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_140_0.35_0.60_stat.out

tail res_mu_150_0.35_0.40_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_150_0.35_0.40_stat.out
tail res_mu_150_0.35_0.60_stat.out | sed -e '9,10d' | awk {'print $5'} > dummy ; sed '3i CLs' dummy > mu_150_0.35_0.60_stat.out

rm dummy
