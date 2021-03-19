
// pt                          0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12
    double pTbin[14] = {0.2, 0.4, 0.6, 0.8, 1.0, 1.4, 1.8, 2.2, 2.8, 3.6, 4.6, 6.0, 7.0, 8.5};

std::pair<double, double> full_range(1.095, 1.14);
std::pair<double, double> signal_range(1.1115, 1.1200);
std::pair<double, double> sb1(1.085, 1.1000);
std::pair<double, double> sb2(1.1450, 1.16);

double mass = 1.115683;
double Dmass = 0.003;
int Nbins = 160;
double sigma = 0.005;

//const std::string signal_func = "[3]*TMath::Gaus(x, [0], [1]) + [4]*TMath::Gaus(x, [0], [2])";
const std::string gaus_func = "[2]*TMath::Gaus(x, [0], [1])";

const std::string poly_bkg4 = "[5] + [6]*x + [7]*x*x + [8]*x*x*x + [9]*x*x*x*x";
const std::string poly_bkg3 = "[5] + [6]*x + [7]*x*x + [8]*x*x*x";
const std::string poly_bkg1 = "[5] + [6]*x";
const std::string poly_exp1 = "TMath::Exp([5] + [6]*x)";

std::string poly_bkg0= "[0] + [1]*x + [2]*x*x + [3]*x*x*x + [4]*x*x*x*x";

const std::string double_gaussian = "[3]*TMath::Gaus(x, [0], [1]) + [4]*TMath::Gaus(x, [0], [2])";
std::string massfunc = double_gaussian + " + " + poly_bkg4;

TH1D * hmass        = 0;
TF1 * fit           = 0;
TF1 * func_signal   = 0;
TF1 * gaus1_signal  = 0;
TF1 * gaus2_signal  = 0;
TF1 * func_bckgnd   = 0;
TFile * f;

bool bPol4 = false;
bool bPol3 = false;
bool bPol1 = false;
bool bExp  = false;

string s = "LM";
string tag = "";
int c = 0;
int ipt = 0;

TF1* fitHist(TH1D* hist, int iter)
{

    /////////
    // Setting up the fit func
    // [0] common mean of double gaussian
    // [1] signal 1 gaussian sigma
    // [2] signal 2 gaussian sigma
    // [3] signal 1 amplitude
    // [4] signal 2 amplitude
    //
    // [5] background pol, 1
    // [6] background pol, x
    // [7] background pol, x*x
    // [8] background pol, x*x*x
    // [9] background pol, x*x*x*x
    //

    TF1 * func = new TF1("func", massfunc.c_str(), full_range.first, full_range.second);

    int cnt = 0;
    for ( int i = 0; i < hist->GetNbinsX(); i++ ) {
        double center = hist->GetBinCenter(i+1);
        if ( (center > sb1.first and center < sb1.second) or (center > sb2.first and center < sb2.second) ) {
            cnt++;
        }
    }

    // sb gr
    TGraphErrors gr(cnt);
    cnt = 0;
    for ( int i = 0; i < hist->GetNbinsX(); i++ ) {
        double center = hist->GetBinCenter(i+1);
        if ( (center > sb1.first and center < sb1.second) or (center > sb2.first and center < sb2.second) ) {
            gr.GetX()[cnt] = center;
            gr.GetY()[cnt] = hist->GetBinContent(i+1);
            gr.GetEY()[cnt] = hist->GetBinError(i+1);
            cnt++;
        }
    }

    func->SetParameter(5, 10.);
    func->SetParameter(6, 1.);
    if ( bPol4 or bPol3 ) func->SetParameter(7, 1.);
    if ( bPol4 or bPol3 ) func->SetParameter(8, 1.);
    if ( bPol4 )          func->SetParameter(9, 1.);

    func->FixParameter(0, mass);
    func->FixParameter(1, 1.);
    func->FixParameter(2, 1.);
    func->FixParameter(3, 0.);
    func->FixParameter(4, 0.);

    gr.Fit(func, "q0");
    gr.Fit(func, "q0");
    gr.Fit(func, "q0");

    func->FixParameter(5, func->GetParameter(5));
    func->FixParameter(6, func->GetParameter(6));
    if ( bPol4 or bPol3 ) func->FixParameter(7, func->GetParameter(7));
    if ( bPol4 or bPol3 ) func->FixParameter(8, func->GetParameter(8));
    if ( bPol4 )          func->FixParameter(9, func->GetParameter(9));

    func->ReleaseParameter(0);
    func->SetParLimits(0, mass-Dmass, mass+Dmass);
    func->ReleaseParameter(1);
    func->ReleaseParameter(2);
    func->ReleaseParameter(3);
    func->ReleaseParameter(4);
    func->SetParLimits(1, 0, sigma);
    func->SetParLimits(2, 0, sigma);
    func->SetParLimits(3, 0, 0.8*hist->GetBinContent(hist->FindBin(mass)));
    func->SetParLimits(4, 0, 0.8*hist->GetBinContent(hist->FindBin(mass)));

    hist->Fit(func, "q0", "", full_range.first, full_range.second);
    hist->Fit(func, "q0", "", full_range.first, full_range.second);
    hist->Fit(func, "q0", "", full_range.first, full_range.second);

    func->ReleaseParameter(0);
    func->ReleaseParameter(1);
    func->ReleaseParameter(2);
    func->ReleaseParameter(3);
    func->ReleaseParameter(4);
    func->ReleaseParameter(5);
    func->ReleaseParameter(6);
    if ( bPol4 or bPol3 ) func->ReleaseParameter(7);
    if ( bPol4 or bPol3 ) func->ReleaseParameter(8);
    if ( bPol4 )          func->ReleaseParameter(9);
    func->SetParLimits(0, mass-Dmass, mass+Dmass);
    func->SetParLimits(1, 0, sigma);
    func->SetParLimits(2, 0, sigma);
    func->SetParLimits(3, 0, 0.8*hist->GetBinContent(hist->FindBin(mass)));
    func->SetParLimits(4, 0, 0.8*hist->GetBinContent(hist->FindBin(mass)));

    for ( int i = 0; i < iter; i++ ) {
        hist->Fit(func, "q0", "", full_range.first, full_range.second);
    }

    return func;
}

void doFit(int c1 = 3, int ipt1 = 6, string y = "Mid", int iter=5)
{
    c = c1;
    ipt = ipt1;

    if ( hmass          ) hmass->Delete();
    if ( fit            ) fit->Delete();
    if ( func_signal    ) func_signal->Delete();
    if ( gaus1_signal   ) gaus1_signal->Delete();
    if ( gaus2_signal   ) gaus2_signal->Delete();
    if ( func_bckgnd    ) func_bckgnd->Delete();

    hmass = (TH1D*) f->Get(Form("hMass%s_%i_%i", y.c_str(), c, ipt));
    fit = fitHist(hmass, iter);

    func_signal  = new TF1("func_signal" , double_gaussian.c_str(), full_range.first, full_range.second);
    gaus1_signal = new TF1("gaus1_signal", gaus_func.c_str(), full_range.first, full_range.second);
    gaus2_signal = new TF1("gaus2_signal", gaus_func.c_str(), full_range.first, full_range.second);
    func_bckgnd  = new TF1("func_bckgnd" , poly_bkg0.c_str(), full_range.first, full_range.second);

    func_signal->SetParameter(0, fit->GetParameter(0));
    func_signal->SetParameter(1, fit->GetParameter(1));
    func_signal->SetParameter(2, fit->GetParameter(2));
    func_signal->SetParameter(3, fit->GetParameter(3));
    func_signal->SetParameter(4, fit->GetParameter(4));

    func_bckgnd->SetParameter(0, fit->GetParameter(5));
    func_bckgnd->SetParameter(1, fit->GetParameter(6));
    if ( bPol4 or bPol3 ) func_bckgnd->SetParameter(2, fit->GetParameter(7));
    if ( bPol4 or bPol3 ) func_bckgnd->SetParameter(3, fit->GetParameter(8));
    if ( bPol4 )          func_bckgnd->SetParameter(4, fit->GetParameter(9));

    func_signal->SetLineColor(kRed);
    func_bckgnd->SetLineColor(kBlue);

    if ( abs(fit->GetParameter(1)) > abs(fit->GetParameter(2)) ) {
        gaus1_signal->SetParameter(0, fit->GetParameter(0));
        gaus1_signal->SetParameter(1, fit->GetParameter(1));
        gaus1_signal->SetParameter(2, fit->GetParameter(3));
        gaus2_signal->SetParameter(0, fit->GetParameter(0));
        gaus2_signal->SetParameter(1, fit->GetParameter(2));
        gaus2_signal->SetParameter(2, fit->GetParameter(4));
    } else {
        gaus2_signal->SetParameter(0, fit->GetParameter(0));
        gaus2_signal->SetParameter(1, fit->GetParameter(1));
        gaus2_signal->SetParameter(2, fit->GetParameter(3));
        gaus1_signal->SetParameter(0, fit->GetParameter(0));
        gaus1_signal->SetParameter(1, fit->GetParameter(2));
        gaus1_signal->SetParameter(2, fit->GetParameter(4));
    }

    gaus1_signal->SetLineColor(kBlue);
    gaus2_signal->SetLineColor(kRed);
    gaus1_signal->SetLineStyle(kDashDotted);
    gaus2_signal->SetLineStyle(kDashDotted);
}

void doFitPA(int c1 = 3, int ipt1 = 6, string y = "Mid", int iter=50)
{
    // c1 = 0, 120
    // c1 = 1, 150
    // c1 = 2, 185
    // c1 = 3, 250
    ipt = ipt1;
    string dir = "vect";
    if ( s == "LM" ) {
        if ( c1 == 0 ) dir += "LmMassN120";
        if ( c1 == 1 ) dir += "LmMassN150";
        if ( c1 == 2 ) dir += "LmMassN185";
        if ( c1 == 3 ) dir += "LmMassN250";
    } else if ( s == "KS" ) {
        if ( c1 == 0 ) dir += "KsMassN120";
        if ( c1 == 1 ) dir += "KsMassN150";
        if ( c1 == 2 ) dir += "KsMassN185";
        if ( c1 == 3 ) dir += "KsMassN250";
    }
    cout << "-->" << Form("%s/h3DPhi_%i", dir.c_str(), ipt1) << endl;

    if ( hmass          ) hmass->Delete();
    if ( fit            ) fit->Delete();
    if ( func_signal    ) func_signal->Delete();
    if ( gaus1_signal   ) gaus1_signal->Delete();
    if ( gaus2_signal   ) gaus2_signal->Delete();
    if ( func_bckgnd    ) func_bckgnd->Delete();

    TH3D * h3D = (TH3D*) f->Get(Form("%s/h3DPhi_%i", dir.c_str(), ipt1));
    hmass = h3D->ProjectionX(Form("hMassMid_%i_%i", c1, ipt1), 0, -1, h3D->GetZaxis()->FindBin(-1.), h3D->GetZaxis()->FindBin(1.)-1);

    fit = fitHist(hmass, iter);

    func_signal  = new TF1("func_signal" , double_gaussian.c_str(), full_range.first, full_range.second);
    gaus1_signal = new TF1("gaus1_signal", gaus_func.c_str(), full_range.first, full_range.second);
    gaus2_signal = new TF1("gaus2_signal", gaus_func.c_str(), full_range.first, full_range.second);
    func_bckgnd  = new TF1("func_bckgnd" , poly_bkg0.c_str(), full_range.first, full_range.second);

    func_signal->SetParameter(0, fit->GetParameter(0));
    func_signal->SetParameter(1, fit->GetParameter(1));
    func_signal->SetParameter(2, fit->GetParameter(2));
    func_signal->SetParameter(3, fit->GetParameter(3));
    func_signal->SetParameter(4, fit->GetParameter(4));

    func_bckgnd->SetParameter(0, fit->GetParameter(5));
    func_bckgnd->SetParameter(1, fit->GetParameter(6));
    if ( bPol4 or bPol3 ) func_bckgnd->SetParameter(2, fit->GetParameter(7));
    if ( bPol4 or bPol3 ) func_bckgnd->SetParameter(3, fit->GetParameter(8));
    if ( bPol4 )          func_bckgnd->SetParameter(4, fit->GetParameter(9));

    func_signal->SetLineColor(kRed);
    func_bckgnd->SetLineColor(kBlue);

    if ( abs(fit->GetParameter(1)) > abs(fit->GetParameter(2)) ) {
        gaus1_signal->SetParameter(0, fit->GetParameter(0));
        gaus1_signal->SetParameter(1, fit->GetParameter(1));
        gaus1_signal->SetParameter(2, fit->GetParameter(3));
        gaus2_signal->SetParameter(0, fit->GetParameter(0));
        gaus2_signal->SetParameter(1, fit->GetParameter(2));
        gaus2_signal->SetParameter(2, fit->GetParameter(4));
    } else {
        gaus2_signal->SetParameter(0, fit->GetParameter(0));
        gaus2_signal->SetParameter(1, fit->GetParameter(1));
        gaus2_signal->SetParameter(2, fit->GetParameter(3));
        gaus1_signal->SetParameter(0, fit->GetParameter(0));
        gaus1_signal->SetParameter(1, fit->GetParameter(2));
        gaus1_signal->SetParameter(2, fit->GetParameter(4));
    }

    gaus1_signal->SetLineColor(kBlue);
    gaus2_signal->SetLineColor(kRed);
    gaus1_signal->SetLineStyle(kDashDotted);
    gaus2_signal->SetLineStyle(kDashDotted);
}

void doSave(bool bPlot = true)
{
    TFile save( ( s + tag + "/" + hmass->GetName() + ".root" ).c_str(), "recreate" );
    hmass->Write("hmass");
    fit->Write();
    func_signal->Write();
    gaus1_signal->Write();
    gaus2_signal->Write();
    func_bckgnd->Write();
    save.Close();

    if ( bPlot ) {
        TCanvas c("c", "c", 800, 600);
        hmass->Draw();
        fit->Draw("same");
        func_signal->Draw("same");
        gaus1_signal->Draw("same");
        gaus2_signal->Draw("same");
        func_bckgnd->Draw("same");
        double S = func_signal->Integral(signal_range.first, signal_range.second)/hmass->GetBinWidth(1);
        double B = func_bckgnd->Integral(signal_range.first, signal_range.second)/hmass->GetBinWidth(1);
        double sig = S/sqrt(S+B);
        TLatex latexS;
        latexS.SetTextFont(43);
        latexS.SetTextSize(22);
        latexS.SetTextAlign(13);
        latexS.DrawLatexNDC(0.56, 0.92, Form("%s: %.1f < p_{T} < %0.1f", s=="LM"?"#Lambda":"K_{s}", pTbin[ipt], pTbin[ipt+1]) );
        latexS.DrawLatexNDC(0.56, 0.87, Form("#chi^{2}/NDF = %.2f", fit->GetChisquare()/fit->GetNDF()));
        latexS.DrawLatexNDC(0.56, 0.82, Form("S = %.2f", S));
        latexS.DrawLatexNDC(0.56, 0.77, Form("B = %.2f", B));
        latexS.DrawLatexNDC(0.56, 0.72, Form("S/#sqrt{S+B} = %.2f", sig));
        c.SaveAs( ( s + tag + "/" + hmass->GetName() + ".pdf" ).c_str() );
        c.SaveAs( ( s + tag + "/" + hmass->GetName() + ".png" ).c_str() );
    }
}

void MVAmassFit(string s1 = "LM", TString option = "pol4")
{
    s = s1;
    if ( s == "LM" ) {
        if ( option.Contains("CentPlus") ) {
            f = new TFile("MVAmassBDT250D4_LM_CentPlus.root");
            tag = "CentPlus";
        } else if ( option.Contains("pPb0") ){
            f = new TFile("pPb16_V0_HM0_rap_merge_v5.root");
            tag = "HM0";
        } else if ( option.Contains("pPb1") ){
            f = new TFile("pPb16_V0_HM123456_rap_merge_v5.root");
            tag = "HM123456";
        } else if ( option.Contains("pPb7") ){
            f = new TFile("pPb16_V0_HM7_rap_merge_v5.root");
            tag = "HM7";
        } else {
            f = new TFile("MVAmassBDT250D4_LM20_cent7.root");
        }
    } else if ( s == "KS" ) {
        if ( option.Contains("CentPlus") ) {
            f = new TFile("MVAmassBDT250D4_KS_CentPlus.root");
            tag = "CentPlus";
        } else if ( option.Contains("pPb0") ){
            f = new TFile("pPb16_V0_HM0_rap_merge_v5.root");
            tag = "HM0";
        } else if ( option.Contains("pPb1") ){
            f = new TFile("pPb16_V0_HM123456_rap_merge_v5.root");
            tag = "HM123456";
        } else if ( option.Contains("pPb7") ){
            f = new TFile("pPb16_V0_HM7_rap_merge_v5.root");
            tag = "HM7";
        } else {
            f = new TFile("MVAmassBDT250D4_KS_cent7.root");
        }
        Nbins = 270;
        //full_range = make_pair<double, double>(0.430, 0.565);
        full_range = make_pair<double, double>(0.450, 0.54);
        signal_range = make_pair<double, double>(0.492, 0.503);
        sb1 = make_pair<double, double>(0.430, 0.489);
        sb2 = make_pair<double, double>(0.506, 0.503);
        mass = 0.497648;
        sigma = 0.01;
        Dmass = 0.005;
    }

    if ( option.Contains("pol4") ) {
        bPol4 = true;
    }
    if ( option.Contains("pol3") ) {
        massfunc = double_gaussian + " + " + poly_bkg3;
        bPol3 = true;
        poly_bkg0= "[0] + [1]*x + [2]*x*x + [3]*x*x*x";
        tag = "pol3";
    }
    if ( option.Contains("pol1") ) {
        massfunc = double_gaussian + " + " + poly_bkg1;
        bPol1 = true;
        poly_bkg0= "[0] + [1]*x";
        tag = "pol1";
    }
    if ( option.Contains("exp") ) {
        massfunc = double_gaussian + " + " + poly_exp1;
        bExp = true;
        poly_bkg0= "TMath::Exp([0] + [1]*x)";
        tag = "exp";
    }
}

