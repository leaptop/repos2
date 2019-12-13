using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private string msAction = null;
        // Commonly-used variable for optional arguments:
        private object moMissing = System.Reflection.Missing.Value;

        private void Form1_Load(object sender, System.EventArgs e)
        {
            radioButton1.Text = "Print report";
            radioButton2.Text = "Preview report";
            radioButton3.Text = "Show form";
            radioButton4.Text = "Print report (Security)";
            radioButton5.Text = "Preview report (Runtime)";
            button1.Text = "Go!";
            radioButton1.Click += new EventHandler(RadioButtons_Click);
            radioButton2.Click += new EventHandler(RadioButtons_Click);
            radioButton3.Click += new EventHandler(RadioButtons_Click);
            radioButton4.Click += new EventHandler(RadioButtons_Click);
            radioButton5.Click += new EventHandler(RadioButtons_Click);
        }

        private void RadioButtons_Click(object sender, System.EventArgs e)
        {
            RadioButton radioBtn = (RadioButton)sender;
            msAction = radioBtn.Text;
        }

        private void button1_Click(object sender, System.EventArgs e)
        {
            // Calls the associated procedure to automate Access, based
            // on the selected radio button on the form.
            switch (msAction)
            {
                case "Print report":
                    Print_Report();
                    break;
                case "Preview report":
                    Preview_Report();
                    break;
                case "Show form":
                    Show_Form();
                    break;
                case "Print report (Security)":
                    Print_Report_Security();
                    break;
                case "Preview report (Runtime)":
                    Preview_Report_Runtime();
                    break;
            }
        }

        private void NAR(object o)
        {
            // Releases the Automation object.
            try // use try..catch in case o is not set
            {
                Marshal.ReleaseComObject(o);
            }
            catch { }
        }

        private Access.Application ShellGetDB(string sDBPath, string sCmdLine,
                 ProcessWindowStyle enuWindowStyle, int iSleepTime)
        {
            //Launches a new instance of Access with a database (sDBPath)
            //using System.Diagnostics.Process.Start. Then, returns the
            //Application object via calling: BindToMoniker(sDBPath). Returns
            //the Application object of the new instance of Access, assuming that
            //sDBPath is not already opened in another instance of Access. To
            //ensure the Application object of the new instance is returned, make
            //sure sDBPath is not already opened in another instance of Access
            //before calling this function.
            // 
            //Example:
            //Access.Application oAccess = null;
            //oAccess = ShellGetDB("c:\\mydb.mdb", null,
            //  ProcessWindowStyle.Minimized, 1000);

            Access.Application oAccess = null;
            string sAccPath = null; //path to msaccess.exe
            Process p = null;

            // Enable exception handler:
            try
            {
                // Obtain the path to msaccess.exe:
                sAccPath = GetOfficeAppPath("Access.Application", "msaccess.exe");
                if (sAccPath == null)

                {
                    MessageBox.Show("Can't determine path to msaccess.exe");
                    return null;
                }

                // Make sure specified database (sDBPath) exists:
                if (!System.IO.File.Exists(sDBPath))
                {
                    MessageBox.Show("Can't find the file '" + sDBPath + "'");
                    return null;
                }

                // Start a new instance of Access passing sDBPath and sCmdLine:
                if (sCmdLine == null)
                    sCmdLine = @"""" + sDBPath + @"""";
                else
                    sCmdLine = @"""" + sDBPath + @"""" + " " + sCmdLine;
                ProcessStartInfo startInfo = new ProcessStartInfo();
                startInfo.FileName = sAccPath;
                startInfo.Arguments = sCmdLine;
                startInfo.WindowStyle = enuWindowStyle;
                p = Process.Start(startInfo);
                p.WaitForInputIdle(60000); //max 1 minute wait for idle input state

                // Move focus back to this form. This ensures that Access
                // registers itself in the ROT:
                this.Activate();

                // Pause before trying to get Application object:
                System.Threading.Thread.Sleep(iSleepTime);

                // Obtain Application object of the instance of Access
                // that has the database open:
                oAccess = (Access.Application)Marshal.BindToMoniker(sDBPath);
                return oAccess;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                // Try to quit Access due to an unexpected error:
                try // use try..catch in case oAccess is not set
                {
                    oAccess.Quit(Access.AcQuitOption.acQuitSaveNone);
                }
                catch { }
                NAR(oAccess);
                oAccess = null;
                return null;
            }
        }

        private Access.Application ShellGetApp(string sCmdLine,
                 ProcessWindowStyle enuWindowStyle)
        {
            //Launches a new instance of Access using System.Diagnostics.
            //Process.Start then returns the Application object via calling:
            //GetActiveObject("Access.Application"). If an instance of
            //Access is already running before calling this function,
            //the function may return the Application object of a
            //previously running instance of Access. If this is not
            //desired, then make sure Access is not running before
            //calling this function, or use the ShellGetDB()
            //function instead. Approach based on Q316125.
            // 
            //Examples:
            //Access.Application oAccess = null;
            //oAccess = ShellGetApp("/nostartup",
            //  ProcessWindowStyle.Minimized);
            // 
            //-or-
            // 
            //Access.Application oAccess = null;
            //string sUser = "Admin";
            //string sPwd = "mypassword";
            //oAccess = ShellGetApp("/nostartup /user " + sUser + "/pwd " + sPwd,
            //  ProcessWindowStyle.Minimized);

            Access.Application oAccess = null;
            string sAccPath = null; //path to msaccess.exe
            Process p = null;
            int iMaxTries = 20; //max GetActiveObject attempts before failing
            int iTries = 0; //GetActiveObject attempts made

            // Enable exception handler:
            try
            {
                // Obtain the path to msaccess.exe:
                sAccPath = GetOfficeAppPath("Access.Application", "msaccess.exe");
                if (sAccPath == null)
                {
                    MessageBox.Show("Can't determine path to msaccess.exe");
                    return null;
                }

                // Start a new instance of Access passing sCmdLine:
                ProcessStartInfo startInfo = new ProcessStartInfo();
                startInfo.FileName = sAccPath;
                startInfo.Arguments = sCmdLine;
                startInfo.WindowStyle = enuWindowStyle;
                p = Process.Start(startInfo);
                p.WaitForInputIdle(60000); //max 1 minute wait for idle input state

                // Move focus back to this form. This ensures that Access
                // registers itself in the ROT:
                this.Activate();

                tryGetActiveObject:
                // Enable exception handler:
                try
                {
                    // Attempt to use GetActiveObject to reference a running
                    // instance of Access:
                    oAccess = (Access.Application)
                       Marshal.GetActiveObject("Access.Application");
                }
                catch
                {
                    //GetActiveObject may have failed because enough time has not
                    //elapsed to find the running Office application. Wait 1/2
                    //second and retry the GetActiveObject. If you try iMaxTries
                    //times and GetActiveObject still fails, assume some other
                    //reason for GetActiveObject failing and exit the procedure.
                    iTries++;
                    if (iTries < iMaxTries)
                    {
                        System.Threading.Thread.Sleep(500); //wait 1/2 second
                        this.Activate();
                        goto tryGetActiveObject;
                    }
                    MessageBox.Show("Unable to GetActiveObject after " +
                       iTries + " tries.");
                    return null;
                }

                // Return the Access Application object:
                return oAccess;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                // Try to quit Access due to an unexpected error:
                try // use try..catch in case oAccess is not set
                {
                    oAccess.Quit(Access.AcQuitOption.acQuitSaveNone);
                }
                catch { }
                NAR(oAccess);
                oAccess = null;
                return null;
            }
        }

        private string GetOfficeAppPath(string sProgId, string sEXE)
        {
            //Returns path of the Office application. e.g.
            //GetOfficeAppPath("Access.Application", "msaccess.exe") returns
            //full path to Microsoft Access. Approach based on Q240794.
            //Returns null if path not found in registry.

            // Enable exception handler:
            try
            {
                Microsoft.Win32.RegistryKey oReg =
                   Microsoft.Win32.Registry.LocalMachine;
                Microsoft.Win32.RegistryKey oKey = null;
                string sCLSID = null;
                string sPath = null;
                int iPos = 0;

                // First, get the clsid from the progid from the registry key
                // HKEY_LOCAL_MACHINE\Software\Classes\<PROGID>\CLSID:
                oKey = oReg.OpenSubKey(@"Software\Classes\" + sProgId + @"\CLSID");
                sCLSID = oKey.GetValue("").ToString();
                oKey.Close();

                // Now that we have the CLSID, locate the server path at
                // HKEY_LOCAL_MACHINE\Software\Classes\CLSID\ 
                // {xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxx}\LocalServer32:
                oKey = oReg.OpenSubKey(@"Software\Classes\CLSID\" + sCLSID +
                   @"\LocalServer32");
                sPath = oKey.GetValue("").ToString();
                oKey.Close();

                // Remove any characters beyond the exe name:
                iPos = sPath.ToUpper().IndexOf(sEXE.ToUpper()); // 0-based position
                sPath = sPath.Substring(0, iPos + sEXE.Length);
                return sPath.Trim();
            }
            catch
            {
                return null;
            }
        }

        private void Print_Report()
        {
            // Prints the "Summary of Sales by Year" report in Northwind.mdb.

            Access.Application oAccess = null;
            string sDBPath = null; //path to Northwind.mdb
            string sReport = null; //name of report to print

            // Enable exception handler:
            try
            {
                sReport = "Summary of Sales by Year";

                // Start a new instance of Access for Automation:
                oAccess = new Access.ApplicationClass();

                // Determine the path to Northwind.mdb:
                sDBPath = oAccess.SysCmd(Access.AcSysCmdAction.acSysCmdAccessDir,
                   moMissing, moMissing).ToString();
                sDBPath = sDBPath + @"Samples\Northwind.mdb";

                // Open Northwind.mdb in shared mode:
                oAccess.OpenCurrentDatabase(sDBPath, false, "");
                // If using Access 10.0 object library, use this instead:
                //oAccess.OpenCurrentDatabase(sDBPath, false, null);

                // Select the report name in the database window and give focus
                // to the database window:
                oAccess.DoCmd.SelectObject(Access.AcObjectType.acReport, sReport, true);

                // Print the report:
                oAccess.DoCmd.OpenReport(sReport,
                   Access.AcView.acViewNormal, moMissing, moMissing,
                   Access.AcWindowMode.acWindowNormal, moMissing);
                // If using Access 10.0 object library, use this instead:
                //oAccess.DoCmd.OpenReport(sReport,
                //  Access.AcView.acViewNormal, moMissing, moMissing,
                //  Access.AcWindowMode.acWindowNormal, moMissing);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
            finally
            {
                // Release any Access objects and quit Access:
                try // use try..catch in case oAccess is not set
                {
                    oAccess.Quit(Access.AcQuitOption.acQuitSaveNone);
                }
                catch { }
                NAR(oAccess);
                oAccess = null;
            }
        }

        private void Preview_Report()
        {
            // Previews the "Summary of Sales by Year" report in Northwind.mdb.

            Access.Application oAccess = null;
            Access.Form oForm = null;
            string sDBPath = null; //path to Northwind.mdb
            string sReport = null; //name of report to preview

            // Enable exception handler:
            try
            {
                sReport = "Summary of Sales by Year";

                // Start a new instance of Access for Automation:
                oAccess = new Access.ApplicationClass();

                // Make sure Access is visible:
                if (!oAccess.Visible) oAccess.Visible = true;

                // Determine the path to Northwind.mdb:
                sDBPath = oAccess.SysCmd(Access.AcSysCmdAction.acSysCmdAccessDir,
                   moMissing, moMissing).ToString();
                sDBPath = sDBPath + @"Samples\Northwind.mdb";

                // Open Northwind.mdb in shared mode:
                oAccess.OpenCurrentDatabase(sDBPath, false, "");
                // If using Access 10.0 object library, use this instead:
                //oAccess.OpenCurrentDatabase(sDBPath, false, null);

                // Close any forms that Northwind may have opened:
                while (oAccess.Forms.Count > 0)
                {
                    oForm = oAccess.Forms[0];
                    oAccess.DoCmd.Close(Access.AcObjectType.acForm,
                       oForm.Name, Access.AcCloseSave.acSaveNo);
                    NAR(oForm);
                    oForm = null;
                }

                // Select the report name in the database window and give focus
                // to the database window:
                oAccess.DoCmd.SelectObject(Access.AcObjectType.acReport, sReport, true);

                // Maximize the Access window:
                oAccess.RunCommand(Access.AcCommand.acCmdAppMaximize);

                // Preview the report:
                oAccess.DoCmd.OpenReport(sReport,
                   Access.AcView.acViewPreview, moMissing, moMissing,
                   Access.AcWindowMode.acWindowNormal, moMissing);
                // If using Access 10.0 object library, use this instead:
                //oAccess.DoCmd.OpenReport(sReport,
                //  Access.AcView.acViewPreview, moMissing, moMissing,
                //  Access.AcWindowMode.acWindowNormal, moMissing);

                // Maximize the report window:
                oAccess.DoCmd.Maximize();

                // Hide Access menu bar:
                oAccess.CommandBars["Menu Bar"].Enabled = false;
                // Also hide NorthWindCustomMenuBar if it is available:
                try
                {
                    oAccess.CommandBars["NorthwindCustomMenuBar"].Enabled = false;
                }
                catch { }

                // Hide Report's Print Preview menu bar:
                oAccess.CommandBars["Print Preview"].Enabled = false;

                // Hide Report's right-click popup menu:
                oAccess.CommandBars["Print Preview Popup"].Enabled = false;

                // Release Application object and allow Access to be closed by user:
                if (!oAccess.UserControl) oAccess.UserControl = true;
                NAR(oAccess);
                oAccess = null;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                // Release any Access objects and quit Access due to error:
                NAR(oForm);
                oForm = null;
                try // use try..catch in case oAccess is not set
                {
                    oAccess.Quit(Access.AcQuitOption.acQuitSaveNone);
                }
                catch { }
                NAR(oAccess);
                oAccess = null;
            }
        }

        private void Show_Form()
        {
            // Shows the "Customer Labels Dialog" form in Northwind.mdb
            // and manipulates controls on the form.

            Access.Application oAccess = null;
            Access.Form oForm = null;
            Access.Controls oCtls = null;
            Access.Control oCtl = null;
            string sDBPath = null; //path to Northwind.mdb
            string sForm = null; //name of form to show

            // Enable exception handler:
            try
            {
                sForm = "Customer Labels Dialog";

                // Start a new instance of Access for Automation:
                oAccess = new Access.ApplicationClass();

                // Make sure Access is visible:
                if (!oAccess.Visible) oAccess.Visible = true;

                // Determine the path to Northwind.mdb:
                sDBPath = oAccess.SysCmd(Access.AcSysCmdAction.acSysCmdAccessDir,
                   moMissing, moMissing).ToString();
                sDBPath = sDBPath + @"Samples\Northwind.mdb";

                // Open Northwind.mdb in shared mode:
                oAccess.OpenCurrentDatabase(sDBPath, false, "");
                // If using Access 10.0 object library, use this instead:
                //oAccess.OpenCurrentDatabase(sDBPath, false, null);

                // Close any forms that Northwind may have opened:
                while (oAccess.Forms.Count > 0)
                {
                    oForm = oAccess.Forms[0];
                    oAccess.DoCmd.Close(Access.AcObjectType.acForm,
                       oForm.Name, Access.AcCloseSave.acSaveNo);
                    NAR(oForm);
                    oForm = null;
                }

                // Select the form name in the database window and give focus
                // to the database window:
                oAccess.DoCmd.SelectObject(Access.AcObjectType.acForm, sForm, true);

                // Show the form:
                oAccess.DoCmd.OpenForm(sForm, Access.AcFormView.acNormal, moMissing,
                   moMissing, Access.AcFormOpenDataMode.acFormPropertySettings,
                   Access.AcWindowMode.acWindowNormal, moMissing);

                // Use Controls collection to edit the form:

                oForm = oAccess.Forms[sForm];
                oCtls = oForm.Controls;

                // Set PrintLabelsFor option group to Specific Country:

                oCtl = (Access.Control)oCtls["PrintLabelsFor"];
                object[] Parameters = new Object[1];
                Parameters[0] = 2; //second option in option group
                oCtl.GetType().InvokeMember("Value", BindingFlags.SetProperty,
                   null, oCtl, Parameters);
                NAR(oCtl);
                oCtl = null;

                // Put USA in the SelectCountry combo box:
                oCtl = (Access.Control)oCtls["SelectCountry"];
                Parameters[0] = true;
                oCtl.GetType().InvokeMember("Enabled", BindingFlags.SetProperty,
                   null, oCtl, Parameters);
                oCtl.GetType().InvokeMember("SetFocus", BindingFlags.InvokeMethod,
                   null, oCtl, null);
                Parameters[0] = "USA";
                oCtl.GetType().InvokeMember("Value", BindingFlags.SetProperty,
                   null, oCtl, Parameters);
                NAR(oCtl);
                oCtl = null;

                // Hide the Database Window:
                oAccess.DoCmd.SelectObject(Access.AcObjectType.acForm, sForm, true);
                oAccess.RunCommand(Access.AcCommand.acCmdWindowHide);

                // Set focus back to the form:
                oForm.SetFocus();

                // Release Controls and Form objects:       
                NAR(oCtls);
                oCtls = null;
                NAR(oForm);
                oForm = null;

                // Release Application object and allow Access to be closed by user:
                if (!oAccess.UserControl) oAccess.UserControl = true;
                NAR(oAccess);
                oAccess = null;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                // Release any Access objects and quit Access due to error:
                NAR(oCtl);
                oCtl = null;
                NAR(oCtls);
                oCtls = null;
                NAR(oForm);
                oForm = null;
                try // use try..catch in case oAccess is not set
                {
                    oAccess.Quit(Access.AcQuitOption.acQuitSaveNone);
                }
                catch { }
                NAR(oAccess);
                oAccess = null;
            }
        }

        private void Print_Report_Security()
        {
            //Shows how to automate Access when user-level
            //security is enabled and you wish to avoid the logon
            //dialog asking for user name and password. In this
            //example we're assuming default security so we simply
            //pass the Admin user with a blank password to print the
            //"Summary of Sales by Year" report in Northwind.mdb.

            Access.Application oAccess = null;
            string sDBPath = null; //path to Northwind.mdb
            string sUser = null; //user name for Access security
            string sPwd = null; //user password for Access security
            string sReport = null; //name of report to print

            // Enable exception handler:
            try
            {
                sReport = "Summary of Sales by Year";

                // Determine the path to Northwind.mdb:
                sDBPath = GetOfficeAppPath("Access.Application", "msaccess.exe");
                if (sDBPath == null)
                {
                    MessageBox.Show("Can't determine path to msaccess.exe");
                    return;
                }
                sDBPath = sDBPath.Substring(0, sDBPath.Length - "msaccess.exe".Length)
                   + @"Samples\Northwind.mdb";
                if (!System.IO.File.Exists(sDBPath))
                {
                    MessageBox.Show("Can't find the file '" + sDBPath + "'");
                    return;
                }

                // Specify the user name and password for the Access workgroup
                // information file, which is used to implement Access security.
                // Note: If you are not using the system.mdw in the default
                // location, you may include the /wrkgrp command-line switch to
                // point to a different workgroup information file.
                sUser = "Admin";
                sPwd = "";

                // Start a new instance of Access with user name and password:
                oAccess = ShellGetDB(sDBPath, "/user " + sUser + " /pwd " + sPwd,
                   ProcessWindowStyle.Minimized, 1000);
                //or
                //oAccess = ShellGetApp(@"""" + sDBPath + @"""" + 
                //  " /user " + sUser + " /pwd " + sPwd,
                //  ProcessWindowStyle.Minimized);

                // Select the report name in the database window and give focus
                // to the database window:
                oAccess.DoCmd.SelectObject(Access.AcObjectType.acReport, sReport, true);

                // Print the report:
                oAccess.DoCmd.OpenReport(sReport,
                   Access.AcView.acViewNormal, moMissing, moMissing,
                   Access.AcWindowMode.acWindowNormal, moMissing);
                // If using Access 10.0 object library, use this instead:                       
                //oAccess.DoCmd.OpenReport(sReport,
                //  Access.AcView.acViewNormal, moMissing, moMissing,
                //  Access.AcWindowMode.acWindowNormal, moMissing);
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
            finally
            {
                // Release any Access objects and quit Access:
                try // use try..catch in case oAccess is not set
                {
                    oAccess.Quit(Access.AcQuitOption.acQuitSaveNone);
                }
                catch { }
                NAR(oAccess);
                oAccess = null;
            }
        }

        private void Preview_Report_Runtime()
        {
            //Shows how to automate the Access Runtime to preview
            //the "Summary of Sales by Year" report in Northwind.mdb.

            Access.Application oAccess = null;
            Access.Form oForm = null;
            string sDBPath = null; //path to Northwind.mdb
            string sReport = null; //name of report to preview

            // Enable exception handler:
            try
            {
                sReport = "Summary of Sales by Year";

                // Determine the path to Northwind.mdb:
                sDBPath = GetOfficeAppPath("Access.Application", "msaccess.exe");
                if (sDBPath == null)
                {
                    MessageBox.Show("Can't determine path to msaccess.exe");
                    return;
                }

                sDBPath = sDBPath.Substring(0, sDBPath.Length - "msaccess.exe".Length)
                               + @"Samples\Northwind.mdb";
                if (!System.IO.File.Exists(sDBPath))
                {
                    MessageBox.Show("Can't find the file '" + sDBPath + "'");
                    return;
                }

                // Start a new instance of Access with a database. If the
                // retail version of Access is not installed, and only the
                // Access Runtime is installed, launches a new instance
                // of the Access Runtime (/runtime switch is optional):
                oAccess = ShellGetDB(sDBPath, "/runtime",
                   ProcessWindowStyle.Minimized, 1000);
                //or
                //oAccess = ShellGetApp(@"""" + sDBPath + @"""" + " /runtime",
                //  ProcessWindowStyle.Minimized);

                // Make sure Access is visible:
                if (!oAccess.Visible) oAccess.Visible = true;

                // Close any forms that Northwind may have opened:
                while (oAccess.Forms.Count > 0)
                {
                    oForm = oAccess.Forms[0];
                    oAccess.DoCmd.Close(Access.AcObjectType.acForm,
                       oForm.Name, Access.AcCloseSave.acSaveNo);
                    NAR(oForm);
                    oForm = null;
                }

                // Select the report name in the database window and give focus
                // to the database window:
                oAccess.DoCmd.SelectObject(Access.AcObjectType.acReport, sReport, true);

                // Maximize the Access window:
                oAccess.RunCommand(Access.AcCommand.acCmdAppMaximize);

                // Preview the report:
                oAccess.DoCmd.OpenReport(sReport,
                   Access.AcView.acViewPreview, moMissing, moMissing,
                   Access.AcWindowMode.acWindowNormal, moMissing);
                // If using Access 10.0 object library, use this instead:
                //oAccess.DoCmd.OpenReport(sReport,
                //  Access.AcView.acViewPreview, moMissing, moMissing,
                //  Access.AcWindowMode.acWindowNormal, moMissing);

                // Maximize the report window:
                oAccess.DoCmd.Maximize();

                // Hide Access menu bar:
                oAccess.CommandBars["Menu Bar"].Enabled = false;
                // Also hide NorthWindCustomMenuBar if it is available:
                try
                {
                    oAccess.CommandBars["NorthwindCustomMenuBar"].Enabled = false;
                }
                catch { }

                // Release Application object and allow Access to be closed by user:
                if (!oAccess.UserControl) oAccess.UserControl = true;
                NAR(oAccess);
                oAccess = null;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                // Release any Access objects and quit Access due to error:
                NAR(oForm);
                oForm = null;
                try // use try..catch in case oAccess is not set
                {
                    oAccess.Quit(Access.AcQuitOption.acQuitSaveNone);
                }
                catch { }
                NAR(oAccess);
                oAccess = null;
            }
        }
    }
}
