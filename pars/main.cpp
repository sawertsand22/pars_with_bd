#include <QCoreApplication>
#include <QTextStream>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include <curl/curl.h>
#include <unordered_set>
#include <iterator>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <chrono>
#include <ctime>
#include <iomanip>


std::string base64_encode(const std::string &s)
{
    static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t i=0,ix=0,leng = s.length();
    std::stringstream q;

    for(i=0,ix=leng - leng%3; i<ix; i+=3)
    {
        q<< base64_chars[ (s[i] & 0xfc) >> 2 ];
        q<< base64_chars[ ((s[i] & 0x03) << 4) + ((s[i+1] & 0xf0) >> 4)  ];
        q<< base64_chars[ ((s[i+1] & 0x0f) << 2) + ((s[i+2] & 0xc0) >> 6)  ];
        q<< base64_chars[ s[i+2] & 0x3f ];
    }
    if (ix<leng)
    {
        q<< base64_chars[ (s[ix] & 0xfc) >> 2 ];
        q<< base64_chars[ ((s[ix] & 0x03) << 4) + (ix+1<leng ? (s[ix+1] & 0xf0) >> 4 : 0)];
        q<< (ix+1<leng ? base64_chars[ ((s[ix+1] & 0x0f) << 2) ] : '=');
        q<< '=';
    }
    return q.str();
}





static size_t write_data(void *content,size_t size,size_t  nmemb, FILE *stream)
{
    size_t written= fwrite(content,size,nmemb,stream);
    return written;

}

void DownloadFile(const char* url, const char* fname)
{
    CURL *curl;
        FILE *fp;
        CURLcode res;
        curl = curl_easy_init();
        if (curl){
            fp = fopen(fname, "wb");
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            fclose(fp);
        }
}
void replaceLinkInFile(const std::string& filePath, const std::string& oldLink, const std::string& newLink) {
    std::ifstream file(filePath);
    std::stringstream buffer;


    buffer << file.rdbuf();
    std::string fileContent = buffer.str();


    size_t pos = fileContent.find(oldLink);
    if (pos != std::string::npos) {
        fileContent.replace(pos, oldLink.size(), newLink);
    }


    file.close();


    std::ofstream outFile(filePath);

    outFile << fileContent;

    outFile.close();
}


int main( int argc, char *argv[])
{
 QCoreApplication a(argc,argv);
 std::cout<<"type command: work/quit"<<std::endl;
 std::string menu_commands;
 std::getline(std::cin,menu_commands);
 while(menu_commands !="work" && menu_commands != "quit")
 {
     std::cout<<"type command: work/quit"<<std::endl;

     std::getline(std::cin,menu_commands);
 }


 while(menu_commands == "work")
{
     std::cout<<"Input url (example https://sawertsand22.github.io): "<<std::endl;
      std::string fild;
      std::getline(std::cin, fild);
         std::cout<<"Input path: "<<std::endl;
       std::string fild2;
       std::getline(std::cin, fild2);
       std::cout<<"Input Category name"<<std::endl;
       std::string fild3;
       std::getline(std::cin,fild3);
    char name[100];
    const char *uurl = fild.c_str();
    std::string qurl = uurl;
   std::string folderPath =fild2;



      sql::mysql::MySQL_Driver *driver;
      sql::Connection *con;
      sql::ResultSet *reso;
      // Подключение к базе данных
      driver = sql::mysql::get_mysql_driver_instance();
      con = driver->connect("tcp://127.0.0.1/Urls", "root", "root");
      sql::Statement *stmt = con->createStatement();
      stmt->execute("USE Urls");
      std::time_t current_time = std::time(nullptr);
       std::tm* datetime = std::localtime(&current_time);
       std::ostringstream datetime_stream;
       datetime_stream << std::put_time(datetime, "%Y-%m-%d %H:%M:%S");
       std::string datetime_mysql = datetime_stream.str();
std::cout << "Текущая дата и время: " << datetime_mysql << std::endl;
      std::string result;
      std::string proverka ="SELECT EXISTS (SELECT * FROM category WHERE categoryname = '"+fild3+"')";
      reso = stmt->executeQuery(proverka);

       bool isAdmin = reso;
     //   std::cout<<"have this category: "<<getool(reso)<<std::endl;


      std::string category_ ="insert into category (categoryname,datechange) values ('"+fild3+"','"+datetime_mysql+"') ON DUPLICATE KEY UPDATE "+"datechange = '"+datetime_mysql+"'";
      stmt->execute(category_);

  CURL *curl;
 FILE *file = fopen("index.html","wb");
 std::string getcontent;
  CURLcode response;
  CURLcode res;
  std::string str_response;
  curl=curl_easy_init();
  curl_easy_setopt(curl,CURLOPT_URL,uurl);
  curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
  curl_easy_setopt(curl,CURLOPT_WRITEDATA,file);
  response = curl_easy_perform(curl);


  res = curl_easy_perform(curl);
  if (res != CURLE_OK)
  {
      std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
  }
  else
  {
      std::cout<<"file opened"<<std::endl;
  }

     // Создание папки, если она не существует
     #ifdef _WIN32
         std::string command = "mkdir " + folderPath;
     #else
         std::string command = "mkdir -p " + folderPath;
     #endif
     system(command.c_str());

   std::ifstream fedit;
   fedit.open("index.html");
   if(!fedit.is_open())
   {
       std::cout<<"err: file not opened"<<std::endl;
   }
   else
   {

       int i=0;
       std::regex linkRegex(R"(\s+(?:[^>]*?\s+)?href=(["'])(.*?)\1)");
       std::regex linkRegex2(R"(\s+(?:[^>]*?\s+)?src=(["'])(.*?)\1)");

       std::string line;
       int lineNumber = 1;
       while (std::getline(fedit, line)) {
           std::smatch match;

           while (  std::regex_search(line, match, linkRegex2)) {
               i++;
               std::cout << "Ссылка найдена на строке " << lineNumber << ": " << match[0] << std::endl;
               line = match.suffix().str();

               std:: string naming;


               auto str = match[2];
               std::cout<<str<<" "<<std::endl;
               std::string po = match[2].str();
               auto poss = po.find_first_of(":");
               auto possq = po.find_first_of("/");

              if(poss>possq || poss>1000)
              {
                   naming=qurl+"/"+std::string(match[2]);
               std::cout<<"link = "<<naming << std::endl;
               }
               else
                   naming=match[2].str();

               const std::string empty;
               auto pos = naming.find_last_of(".");
                auto posq =naming.find_last_of("/");
               std::string sbs = naming.substr(pos+1);
                std::string fq = std::string ("./")+folderPath+"/"+"file_" +std::to_string(i)+"."+naming.substr(pos+1);






           if(naming.length()>0 &&   pos>posq && posq!=0)

                {
                    std:: cout<<"name file:  "<<fq<<std::endl<<pos<<" "<<posq<<std::endl;
                DownloadFile(naming.c_str(), fq.c_str());
                replaceLinkInFile("index.html", match[2], fq);
                }

           }




           while (  std::regex_search(line, match, linkRegex)) {
               i++;
               std::cout << "Ссылка найдена на строке " << lineNumber << ": " << match[0] << std::endl;
               line = match.suffix().str();
               std:: string naming;

               auto str = match[2];
               std::cout<<str<<" "<<std::endl;
               std::string po = match[2].str();
               auto poss = po.find_first_of(":");
               auto possq = po.find_first_of("/");

              if(poss>possq || poss>1000)
              {
                   naming=qurl+"/"+std::string(match[2]);
               std::cout<<"link = "<<naming << std::endl;
               }
               else
                   naming=match[2].str();

               const std::string empty;
               auto pos = naming.find_last_of(".");
                auto posq =naming.find_last_of("/");
               std::string sbs = naming.substr(pos+1);
                std::string fq = std::string ("./")+folderPath+"/"+"file_" +std::to_string(i)+"."+naming.substr(pos+1);




           if(naming.length()>0 &&   pos>posq && posq!=0)

                {
                    std:: cout<<"name file:  "<<fq<<std::endl<<pos<<" "<<posq<<std::endl;
                DownloadFile(naming.c_str(), fq.c_str());
                replaceLinkInFile("index.html", match[2], fq);
                }

           }













           lineNumber++;

}


    fedit.close();







  }
curl_easy_cleanup(curl);
     std::time_t current_time1 = std::time(nullptr);

      // Преобразование в формат datetime MySQL
      std::tm* datetime1 = std::localtime(&current_time1);
      std::ostringstream datetime_stream1;
      datetime_stream1 << std::put_time(datetime1, "%Y-%m-%d %H:%M:%S");
      std::string datetime_mysql1 = datetime_stream1.str();
std::cout << "Текущая дата и время: " << datetime_mysql1 << std::endl;

std::cout<<"type command: work/quit"<<std::endl;

std::getline(std::cin,menu_commands);
        std::ifstream fin("index.html");

        std::string strh;
        std::string str1;

        while(!fin.eof()){
        std:: getline(fin, strh);
        str1 += strh;
        if (!fin.eof()){
            str1 += '\n';
        }
        }
        fin.close();



      std::string links_ = "insert into links (idcategory,name,context,datechange) values ((SELECT idcategory FROM category  where categoryname = '"+fild3+"' ORDER BY idcategory DESC limit 1),'"+fild2+"','"+base64_encode(str1)+"','"+datetime_mysql1+"')";
        stmt->execute(links_);


        delete stmt;
        delete con;
        delete reso;
        std::cout<<"type command: work/quit"<<std::endl;

        std::getline(std::cin,menu_commands);
        if(menu_commands!="work"&&menu_commands!="quit")
        {
            std::cout<<"type command: work/quit"<<std::endl;

            std::getline(std::cin,menu_commands);
            if(menu_commands=="quit")
                return 0;
        }
}

if(menu_commands=="quit")
    return 0;
}
