
const int nmass=7;
double cls_exp[7];
double cls_exp_8tev[7];
double cls_obs[7];
double cls_exp_pm1[14];
double cls_exp_pm2[14];
double cls_exp2[7];
double cls_exp2_pm1[14];
double cls_exp2_pm2[14];
double clsb_exp[7];
double clsb_exp_pm1[14];
double clsb_exp_pm2[14];
double clsb_obs[14];

int mass_points[14];

void readAtlas();
//TGraph* getD0Limits();
//TGraph* getCDFLimits();

void makeAsymptoticPlot() {

  //  gROOT->LoadMacro("~/info/tdrstyle.C");
  //setTDRStyle();
  gStyle->SetPadTopMargin(0.1);

  //  gROOT->LoadMacro("AtlasLabels.C");

  // For Alex on Laptop
  //gROOT->LoadMacro("./atlasstyle-00-03-04/AtlasStyle.C");
  //gROOT->LoadMacro("./atlasstyle-00-03-04/AtlasUtils.C");
  //gROOT->LoadMacro("./atlasstyle-00-03-04/AtlasLabels.C");
  //  SetAtlasStyle();

  //  gStyle->SetPadLeftMargin( 0.7* gStyle->GetPadLeftMargin() );
  //gStyle->SetPadRightMargin( 0.7* gStyle->GetPadRightMargin() );

  // read results
  cout << "reading in results" << endl;
  readAtlas();

  //UK  TGraph* g_cdf = getCDFLimits();
  //UK  TGraph* g_d0 = getD0Limits();

  // set up TGraphs
  TGraph* g_cls_exp = new TGraph(nmass);
  //TGraph* g_cls_exp_8tev = new TGraph(nmass);
  TGraph* g_cls_obs = new TGraph(nmass);
  TGraphAsymmErrors* g_cls_exp_pm1 = new TGraphAsymmErrors(nmass);
  TGraphAsymmErrors* g_cls_exp_pm2 = new TGraphAsymmErrors(nmass);
  TGraph* g_cls_exp2 = new TGraph(nmass);
  TGraphAsymmErrors* g_cls_exp2_pm1 = new TGraphAsymmErrors(nmass);
  TGraphAsymmErrors* g_cls_exp2_pm2 = new TGraphAsymmErrors(nmass);
  TGraph* g_clsb_exp = new TGraph(nmass);
  TGraphAsymmErrors* g_clsb_exp_pm1 = new TGraphAsymmErrors(nmass);
  TGraphAsymmErrors* g_clsb_exp_pm2 = new TGraphAsymmErrors(nmass);
  TGraph* g_clsb_obs = new TGraph(nmass);
  g_cls_exp->SetLineWidth(2);
  g_cls_obs->SetLineWidth(2);
  g_cls_exp2->SetLineWidth(2);
  //g_cls_exp_8tev->SetLineWidth(2);
  g_clsb_exp->SetLineWidth(2);
  g_clsb_obs->SetLineWidth(2);


  for(int i=0; i<nmass; ++i) {
    const int mass = mass_points[i];
    cout << mass << " " << clsb_obs[i] << endl;
    g_cls_exp->SetPoint(i, mass, cls_exp[i]);
    g_cls_obs->SetPoint(i, mass, cls_obs[i]);
    g_clsb_exp->SetPoint(i, mass, clsb_exp[i]);
    g_clsb_obs->SetPoint(i, mass, clsb_obs[i]);
    g_cls_exp2->SetPoint(i, mass, cls_exp2[i]);
    //g_cls_exp_8tev->SetPoint(i, mass, cls_exp_8tev[i]);
	
    g_cls_exp_pm1->SetPoint(i,mass, cls_exp[i]);
    g_cls_exp_pm1->SetPointError(i, 10, 10, cls_exp[i]-cls_exp_pm1[i+7], cls_exp_pm1[i]-cls_exp[i]);
				  
    g_cls_exp_pm2->SetPoint(i,mass, cls_exp[i]);
    g_cls_exp_pm2->SetPointError(i, 10, 10, cls_exp[i]-cls_exp_pm2[i+7], cls_exp_pm2[i]-cls_exp[i]);

    //g_cls_exp2_pm1->SetPoint(i,mass, cls_exp2[i]);
    //g_cls_exp2_pm1->SetPointError(i, 10, 10, cls_exp2[i]-cls_exp2_pm1[i+7], cls_exp2_pm1[i]-cls_exp2[i]);
    
    //g_cls_exp2_pm2->SetPoint(i,mass, cls_exp2[i]);
    //g_cls_exp2_pm2->SetPointError(i, 10, 10, cls_exp2[i]-cls_exp2_pm2[i+7], cls_exp2_pm2[i]-cls_exp2[i]);
    
    g_clsb_exp_pm1->SetPoint(i, mass, clsb_exp_pm1[i]);
    g_clsb_exp_pm1->SetPoint(5-i, mass, clsb_exp_pm1[i+3]);
  }//mass loop
  
  g_cls_exp->SetLineColor(kRed);
  g_cls_obs->SetLineColor(kBlack);
  g_cls_obs->SetMarkerColor(kBlack);
  g_cls_exp->SetLineStyle(2);

  //  g_cls_exp->SetLineColor(2);

  g_cls_exp2->SetLineColor(kBlue);
  //g_cls_exp_8tev->SetLineColor(1);
    g_cls_exp2->SetLineStyle(2);
  
  g_clsb_exp->SetLineColor(kRed);
  g_clsb_obs->SetLineColor(kRed);
  g_clsb_obs->SetMarkerColor(kRed);
  g_clsb_exp->SetLineStyle(2);

  g_cls_exp_pm1->SetFillColor(kGreen);
  g_cls_exp_pm1->SetLineColor(kGreen);
  /*
  g_cls_exp2_pm1->SetFillColor(kGreen-5);
  g_cls_exp2_pm1->SetFillStyle(3004);
  g_cls_exp2_pm1->SetLineColor(kGreen-5);
  */
  g_cls_exp_pm2->SetFillColor(kYellow);
  g_cls_exp_pm2->SetLineColor(kYellow);
  /*
  g_cls_exp2_pm2->SetFillColor(kYellow-8);
  g_cls_exp2_pm2->SetFillStyle(3005);
  g_cls_exp2_pm2->SetLineColor(kYellow-8);
  */

  // TCanvas *c4 = new TCanvas();
  //c4->

  TCanvas* c = new TCanvas("c1","asymptotic results",900,700);
  //  c->SetLogy();
  //  c->DrawFrame(90,0,150,0.1,"");
  //  c->SetLogy();
  c->cd();
  // c->SetLogy();

  TH2F *chist = new TH2F("chist","",12,90.0,150.0,10,0.0,0.1);
  chist->Draw();

  g_cls_exp_pm2->Draw("a3 same");
  g_cls_exp_pm2->GetHistogram()->SetYTitle("Limit on B(t #rightarrow H^{+}b) with B(H^{+}#rightarrow c#bar{b}) = 1");
  //  g_cls_exp_pm2->GetHistogram()->SetMaximum(0.1);
  //  g_cls_exp_pm2->GetHistogram()->SetYTitleSize(0.05);
  g_cls_exp_pm2->GetHistogram()->GetYaxis()->SetTitleSize(0.035);
  g_cls_exp_pm2->GetHistogram()->GetYaxis()->SetLabelSize(0.03);
  g_cls_exp_pm2->GetHistogram()->GetYaxis()->SetTitleOffset(1.5);
  //  g_cls_exp_pm2->GetHistogram()->GetYaxis()->CenterTitle(true);
  //g_cls_exp_pm2->GetHistogram()->GetYaxis()->SetRangeUser(0.0, 0.01);
  g_cls_exp_pm2->GetHistogram()->GetYaxis()->SetRangeUser(0.0, 0.01);
  g_cls_exp_pm2->GetHistogram()->GetXaxis()->SetRangeUser(90.0, 150.0);
  g_cls_exp_pm2->GetHistogram()->SetXTitle("m_{H^{+}} (GeV)");

  g_cls_exp_pm1->Draw("3 same");

  g_cls_exp->SetLineWidth(4);
  g_cls_exp->Draw("l same");

  //  g_cls_obs->Draw("pl same");

  //g_cls_exp2_pm2->Draw("3 same");
  //g_cls_exp2_pm1->Draw("3 same");
  

  g_cls_exp->SetLineWidth(4);
  g_cls_exp->Draw("l same");

  g_cls_exp2->SetLineWidth(4);
  g_cls_exp2->SetLineStyle(3);
  g_cls_exp2->Draw("l same");
  
  g_cls_obs->SetLineWidth(4);
  g_cls_obs->Draw("pl same");



  
  /* UK
  g_clsb_exp->Draw("l same");
  g_clsb_obs->Draw("pl same");
  cout << "CLsb obs:" << endl;
  for(int i=0; i<g_clsb_obs->GetN(); ++i) {
    double x,y;
    g_clsb_obs->GetPoint(i,x,y);
    cout << i << " " << x << " " << y << endl;
  }

  g_cdf->Draw("l same");
  g_d0->Draw("l same");
  */

  TLegend *leg= new TLegend(0.55,0.63,0.9,0.84);
  leg->SetFillColor(0);
  leg->SetBorderSize(0);
  leg->SetTextFont(4);
  leg->AddEntry(g_cls_exp, "Expected Limit, mva cut(0.35,0.40)","l");
  leg->AddEntry(g_cls_exp_pm1, "Expected #pm 1#sigma","f");
  leg->AddEntry(g_cls_exp_pm2, "Expected #pm 2#sigma","f");
  leg->AddEntry(g_cls_exp2, "Expected Limit, mva cut(0.35,0.60)","l");
  //leg->AddEntry(g_cls_exp2_pm1, "Expected #pm 1#sigma","f");
  //leg->AddEntry(g_cls_exp2_pm2, "Expected #pm 2#sigma","f");

  /* UK
  leg->AddEntry(g_clsb_exp, "Expected, CL_{s+b}","l");
  leg->AddEntry(g_clsb_obs, "Observed, CL_{s+b}","lp");
  leg->AddEntry(g_cdf, "CDF Observed","l");
  leg->AddEntry(g_d0, "D0 Observed","l");
  */

  //leg->Draw("same");
  TLegend *leg2= new TLegend(0.6,0.5,0.9,0.8);
  leg2->SetFillColor(0);
  leg2->SetBorderSize(0);
  leg2->SetTextFont(42);
  //leg2->AddEntry(g_cls_exp2, "Expected (stat. only)","l");
  leg2->AddEntry(g_cls_exp, "Expected","l");
  leg2->AddEntry(g_cls_exp_pm1, "Expected #pm 1#sigma","f");
  leg2->AddEntry(g_cls_exp_pm2, "Expected #pm 2#sigma","f");
  leg2->AddEntry(g_cls_obs, "Observed","lp"); 
  leg2->Draw();
  
  TLatex *latex = new TLatex();
  latex->SetTextSize(0.05);
  latex->SetNDC(kTRUE);
  latex->SetTextFont(62);
  latex->DrawLatex(0.13,0.83,"CMS");
  latex->SetTextFont(42);
  latex->SetTextSize(0.04);
  latex->DrawLatex(0.13,0.78,"#it{Preliminary}");
  latex->SetTextFont(42);
  latex->DrawLatex(0.7, 0.92,"19.7 fb^{-1} (8 TeV)");
  //    latex->DrawLatex(0.18, 0.92,"e+jets, #geq 3 b-tagged events, #sigma(stat.) only");
  //  latex->DrawLatex(0.18, 0.92,"e+jets, #geq 3 b-tagged events");
  //  latex->DrawLatex(0.18, 0.92,"#mu+jets, #geq 3 b-tagged events");
  //  latex->DrawLatex(0.18, 0.92,"#mu+jets, #geq 3 b-tagged events, #sigma(stat.) only");
  //  latex->DrawLatex(0.18, 0.92,"#mu+jets, 2 b-tagged events, #sigma(stat.) only");
  //  latex->DrawLatex(0.18, 0.92,"#mu+jets, 2 b-tagged events");
  //  latex->DrawLatex(0.57, 0.83,"Combined e+#mu channels");
  //  latex->DrawLatex(0.18, 0.92,"Combined e+#mu channels, #sigma(stat.) only");
  //  latex->DrawLatex(0.18, 0.92,"e+jets, #geq 2 b-tagged events, #sigma(stat.) only");
  latex->DrawLatex(0.5, 0.85,"#mu/e+jets, #geq 2 b-tagged events");
  //  latex->DrawLatex(0.18, 0.92,"e+jets, 2 b-tagged events");
  //latex->DrawLatex(0.18, 0.92,"e+jets, 2 b-tagged events, #sigma(stat.) only");
    //latex->DrawLatex(0.18, 0.92,"#mu+jets, #geq 2 b-tagged events, #sigma(stat.) only");
  //  latex->DrawLatex(0.18, 0.92,"#mu+jets, #geq 2 b-tagged events");

  //ATLAS (prelim)
  //  ATLASLabel(0.20,0.80,"internal");

  //leg2->Draw("same");

  //  c->Print("asymptotic_limits.eps");
  //  c->SaveAs("asymptotic_limits.pdf");
			

  //  leg3->AddEntry(g_cls_obs, "Observed Limit","lp");
  //  leg3->AddEntry(g_cdf, "CDF Observed","l");
  //  leg3->AddEntry(g_d0, "D0 Observed","l");
  /*
  TCanvas* c2 = new TCanvas("c2","c2",700,500);
  //  c2->SetLogy();
  //g_clsb_exp->SetLineWidth(2);
  //g_clsb_obs->SetLineWidth(2);
  chist->Draw();
  g_clsb_exp_pm2->GetHistogram()->SetYTitle("B(t #rightarrow H^{+}b) #times B(H^{+}#rightarrow c#bar{b}) = 1");
  g_cls_exp_pm2->Draw("a3 same");
  g_cls_exp_pm1->Draw("3 same");
  g_cls_exp->Draw("l same");
  //g_cls_obs->Draw("pl same");

  leg2->Draw("same");

  //latex = new TLatex();
  //latex->SetTextSize(0.05);
  //latex->SetNDC(kTRUE);
  //  latex->DrawLatex(0.40, 0.80, "#int L =19.7 fb^{-1}");
  
  //ATLAS (prelim)
  //  ATLASLabel(0.20,0.80,"Preliminary");

  //  c2->Print("asymptotic_limits_pclonly.eps");
  */
  TCanvas* c3 = new TCanvas("c3","c3",900,700);
  //  c3->SetLogy();
  //  chist->Draw();
  c3->cd();
  //  c3->SetLogy();
  chist->Draw();
  g_cls_exp_pm2->Draw("a3 same");
  g_cls_exp_pm1->Draw("3 same");
  g_cls_exp->SetLineWidth(4);
  //g_cls_exp_8tev->Draw("l same");
  g_cls_exp->Draw("l same");
  //  g_cls_obs->Draw("pl same");

  g_cls_exp2->Draw("l same");


  /*
  g_cdf->Draw("l same");
  g_d0->Draw("l same");
  */
  TLegend *leg3= new TLegend(0.45,0.5,0.9,0.8);
  leg3->SetFillColor(0);
  leg3->SetBorderSize(0);
  leg3->SetTextFont(42);
  leg3->SetHeader("Upper limit @95% CL");
  leg3->AddEntry(g_cls_exp, "Expected Limit","l");
  leg3->AddEntry(g_cls_exp_pm1, "Expected #pm 1#sigma","f");
  leg3->AddEntry(g_cls_exp_pm2, "Expected #pm 2#sigma","f");
  leg3->AddEntry(g_cls_exp2, "Expected Limit, 8TeV","l");
  //leg3->AddEntry(g_cls_exp_8tev, "Expected Limit @8TeV, 19.7fb^{-1}","l");
  leg3->Draw();


  latex->SetTextSize(0.05);
  latex->SetNDC(kTRUE);
  latex->SetTextFont(62);
  latex->DrawLatex(0.13,0.83,"CMS");
  latex->SetTextFont(42);
  latex->SetTextSize(0.04);
  latex->DrawLatex(0.13,0.78,"#it{Preliminary}");
  latex->DrawLatex(0.7, 0.92,"35.9 fb^{-1} (13 TeV)");
  latex->DrawLatex(0.4, 0.85,"#mu/e+jets, #geq 2 b-tagged events, stat. only");

}// makeAsymptoticPlot()


void readAtlas() {
  mass_points[0] = 90;
  mass_points[1] = 100;
  mass_points[2] = 110;
  mass_points[3] = 120;
  mass_points[4] = 130;
  mass_points[5] = 140;
  mass_points[6] = 150;

  cout << "looping over " << nmass << endl;
  for(int i=0; i<nmass; ++i) {
    const int mass = mass_points[i];

    ifstream ifile(Form("combine/Comb_%i_0.00_0.00_stat_only.out",mass));

    string temp;
    cout << "starting on file " << Form("res_stat_%i.txt",mass) << endl;
    while(ifile >> temp && !ifile.eof()) {
      cout << "read " << temp.c_str() << endl;
      if(temp.compare("CLs")==0) {
	double obs, dummy, expp2, expp1, exp, expm1, expm2;
	ifile >> obs;
	//	ifile >> dummy;
	ifile >> expp2; // 2sigma expected
	ifile >> expp1; // 1sigma 
	ifile >> exp;
	ifile >> expm1; // -1sigma
	ifile >> expm2; // -2sigma
	cls_exp[i] = exp;
	cls_obs[i] = obs;
	cls_exp_pm1[i] = expp1;
	cls_exp_pm1[i+7] = expm1;
	cls_exp_pm2[i] = expp2;
	cls_exp_pm2[i+7] = expm2;
      }if(temp.compare("CLsb")==0) {
	double obs, expp2, expp1, exp, expm1, expm2;
	ifile >> obs;
	ifile >> expp2;
	ifile >> expp1;
	ifile >> exp;
	ifile >> expm1;
	ifile >> expm2;
	clsb_exp[i] = exp;
	clsb_obs[i] = obs;
	clsb_exp_pm1[i] = expp1;
	clsb_exp_pm1[i+7] = expm1;
	clsb_exp_pm2[i] = expp2;
	clsb_exp_pm2[i+7] = expm2;

      }
    }//loop over file
      
  }//mass point loop

  for(int i=0; i<nmass; ++i) {
	  const int mass = mass_points[i];

	  ifstream ifile(Form("combine/Comb_8TeV_%i_stat_only.out",mass));
	  string temp;
	  cout << "starting on file " << Form("res_ctag_stat_%i.txt",mass) << endl;
	  while(ifile >> temp && !ifile.eof()) {
		  cout << "read " << temp.c_str() << endl;
		  if(temp.compare("CLs")==0) {
			  double obs, dummy, expp2, expp1, exp, expm1, expm2;
			  ifile >> obs;
			  //	ifile >> dummy;
			  ifile >> expp2;
			  ifile >> expp1;
			  ifile >> exp;
			  ifile >> expm1;
			  ifile >> expm2;
			  cls_exp2[i] = exp;
			  //	  cls_obs[i] = obs;
			  cls_exp2_pm1[i] = expp1;
			  cls_exp2_pm1[i+7] = expm1;
			  cls_exp2_pm2[i] = expp2;
			  cls_exp2_pm2[i+7] = expm2;
		  }
	  }//loop over file
      
  }//mass point loop
  /* // I don't have 8TeV data
  for(int i=0; i<nmass; ++i) {
	  const int mass = mass_points[i];

	  ifstream ifile(Form("CHtoCB_comb_%i_stat.out",mass));
	  
	  string temp;
	  cout << "starting on file " << Form("res_8tev_stat_%i.txt",mass) << endl;
	  while(ifile >> temp && !ifile.eof()) {
		  cout << "read " << temp.c_str() << endl;
		  if(temp.compare("CLs")==0) {
			  double obs, dummy, expp2, expp1, exp, expm1, expm2;
			  ifile >> obs;
			  //	ifile >> dummy;
			  ifile >> expp2;
			  ifile >> expp1;
			  ifile >> exp;
			  ifile >> expm1;
			  ifile >> expm2;
			  cls_exp_8tev[i] = exp;
			  //	  cls_obs[i] = obs;
			  //			  cls_exp2_pm1[i] = expp1;
			  // cls_exp2_pm1[i+7] = expm1;
			  //cls_exp2_pm2[i] = expp2;
			  //cls_exp2_pm2[i+7] = expm2;
		  }
	  }//loop over file
      
  }//mass point loop
  */
}//readAtlas

/*
TGraph* getD0Limits() {
  // Get tevatron limits
  ifstream input("d0_limits.dat");
  if (!input) cout<< " can't open input file " << endl;
  
  int i=0;
  Float_t tmass,tbr;
  const Int_t nd0=5;
  
  Float_t tx[nd0], ty[nd0];
  
  cout << "D0 limits:" << endl;
  while(input) {
    
    input >> tmass >> tbr;
    
    tx[i] = tmass;
    ty[i] = tbr;
    std::cout << ty[i] << std::endl;
    i++;    
  }
  
  TGraph* gr6 = new TGraph(i,tx,ty);
  gr6->SetLineStyle(3);
  gr6->SetLineWidth(3);
  gr6->SetLineColor(kViolet);
  gr6->SetMarkerColor(kViolet);

  return gr6;
}

TGraph* getCDFLimits() {

  // Get tevatron limits
   ifstream input("cdf_limits.dat");
   if (!input) cout<< " can't open input file " << endl;
   
   int i=0;
   Float_t tmass,tbr;
   const Int_t nbins=6;

   Float_t tx[nbins], ty[nbins];
     
     while(input) {
       
       input >> tmass >> tbr;
       
       tx[i] = tmass;
       ty[i] = tbr;
       std::cout << ty[i] << std::endl;
       i++;    
     }
   
     TGraph* gr3 = new TGraph(i,tx,ty);
     gr3->SetLineStyle(4);
     gr3->SetLineWidth(3);
     gr3->SetLineColor(kBlue);
     gr3->SetMarkerColor(kBlue);
     return gr3;
}
*/
