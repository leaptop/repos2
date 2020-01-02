// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book 
//             "Qt 5.3 Professional programming with C++"
// ======================================================================
//  Copyright (c) 2014 by Max Schlee
//
//  Email : Max.Schlee@neonway.com
//  Blog  : http://www.maxschlee.com
//
//  Social Networks
//  ---------------
//  FaceBook : http://www.facebook.com/mschlee
//  Twitter  : http://twitter.com/Max_Schlee
//  2Look.me : http://2look.me/NW100003
//  Xing     : http://www.xing.com/profile/Max_Schlee
//  vk.com   : https://vk.com/max.schlee
// ======================================================================

#include <QtWidgets>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTextEdit    txt;

    txt.setHtml("<HTML>"
                "<BODY BGCOLOR=MAGENTA>"
                "<CENTER><IMG SRC=\":/MetroGnome.png\"></CENTER>"
                "<H2><CENTER>Gnome Poem 3: Magic Magic</CENTER></H2>"
                "<H3><CENTER>(http://ynstyn.tripod.com)</CENTER><H3>"
                "<FONT COLOR=BLUE>"
                "<P ALIGN=\"center\">"
                    "<I>"
                    "Magic! Magic!<BR>"
                    "Are you here?<BR>"
                    "Abra-ca-dabra!<BR>"
                    "We appear.<BR><BR>"
                    "Magic! Magic!<BR>"
                    "Gnomes are we.<BR>"
                    "Magic gnomes<BR>"
                    "Of mystery.<BR>"
                    "..."
                    "</I>"
                "</P>"
                "</FONT>"
                "</BODY>"
                "</HTML>"
               );
    txt.resize(320, 450);
    txt.show();

    return app.exec();
}
