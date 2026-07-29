#include <iostream>
#include <string>
#include <vector>
#include <fstream>


// =============== STRUCT DEFINITIONS ===============
struct STIGFinding {
  std::string id;
  std::string category;
  std::string description;
  std::string status;
};


// =============== FUNCTIONS ===================
int count_open_findings(std::vector<STIGFinding> findings) {
  int num = 0;
  for (int i = 0; i < findings.size(); ++i) {
    if (findings[i].status == "Open") {
      num += 1;
    }

  }
  return num;
}

int count_not_findings(std::vector<STIGFinding> findings) {
  int num = 0;
  for (int i = 0; i < findings.size(); ++i) {
    if (findings[i].status == "Not a Finding") {
      num += 1;
    }

  }
  return num;
}

int count_by_category(std::vector<STIGFinding> findings, std::string category) {
  int num = 0;
  for (int i = 0; i < findings.size(); ++i) {
    if (findings[i].category == category) {
      num += 1;
    }
  }
  return num;
}

int has_cat_one(std::vector<STIGFinding> findings) {
  int num = 0;
  for (int i = 0; i < findings.size(); ++i) {
    if (findings[i].category == "CAT I") {
      num += 1;
    }
  }
  return num;
}

int has_cat_two(std::vector<STIGFinding> findings) {
  int num = 0;
  for (int i = 0; i < findings.size(); ++i) {
    if (findings[i].category == "CAT II") {
      num += 1;
    }
  }
  return num;
}

int has_cat_three(std::vector<STIGFinding> findings) {
  int num = 0;
  for (int i = 0; i < findings.size(); ++i) {
    if (findings[i].category == "CAT III") {
      num += 1;
    }
  }
  return num;
}

void print_report(std::vector<STIGFinding> findings) {
  std::cout << "==========STIG REPORT==========\n\n";
  int findingcount = findings.size();
  std::cout << "-- There were " << findingcount << " findings in total. --\n\n";

  int cat_one_findings = has_cat_one(findings);
  int cat_two_findings = has_cat_two(findings);
  int cat_three_findings = has_cat_three(findings);

  std::cout << "-- Of these findings, " << cat_one_findings << " result(s) were CAT I.\n" << cat_two_findings << " result(s) were CAT II.\n" << "and " << cat_three_findings << " result(s) were CAT III. --\n\n";

  int open_findings = count_open_findings(findings);
  int not_findings = count_not_findings(findings);
  std::cout << "-- In total, " << open_findings << " open result(s) were found, and " << not_findings << " result(s) were not a finding. --\n\n" << "==========END REPORT==========\n";
    
  std::ofstream outfile("stig_report.txt");
  outfile << "==========STIG REPORT==========\n\n";
  outfile << "-- There were " << findingcount << " findings in total. --\n\n";
  outfile << "-- Of these findings, " << cat_one_findings << " result(s) were CAT I.\n" << cat_two_findings << " result(s) were CAT II.\n" << "and " << cat_three_findings << " result(s) were CAT III. --\n\n";
  outfile << "-- In total, " << open_findings << " open result(s) were found, and " << not_findings << " result(s) were not a finding. --\n\n" << "==========END REPORT==========\n";
  outfile.close();

}

//=============== MAIN ================
int main() {

  int num_of_findings = 0;
  std::cout << "How many findings do you want to enter?\n";
  std::cin >> num_of_findings;
  std::cin.ignore();

  std::vector<STIGFinding> findings;

  for (int i = 0; i < num_of_findings; ++i) {
    
    STIGFinding temp;

    std::cout << "What is the ID of your vuln?\n";
    std::getline(std::cin, temp.id);

    do {
      std::cout << "What is the category of your vuln?\n";
      std::getline(std::cin, temp.category);
      if (temp.category != "CAT I" && temp.category != "CAT II" && temp.category != "CAT III") {
        std::cout << "Invalid category. Please only enter 'CAT I', 'CAT II', or 'CAT III'.";
      }
    } while (temp.category != "CAT I" && temp.category != "CAT II" && temp.category != "CAT III");

    std::cout << "What is the description of your vuln\n";
    std::getline(std::cin, temp.description);

    do {
      std::cout << "What is the status of your vuln?\n";
      std::getline(std::cin, temp.status);
      if (temp.status != "Open" && temp.status != "Not a Finding" && temp.status != "Not Reviewed" && temp.status != "Not Applicable") {
        std::cout << "Invalid status. Please only enter 'Not a Finding', 'Open', 'Not Reviewed', or 'Not Applicable'.";
      }
    } while (temp.status != "Open" && temp.status != "Not a Finding" && temp.status != "Not Reviewed" && temp.status != "Not Applicable");

    findings.push_back(temp);

    std::cout << "\n" << "Finding " << i + 1 << " complete.\n\nEnter the information for the next finding below.\n";
  }

  for (int i = 0; i < findings.size(); ++i) {
    std::cout << "Finding " << i + 1 << ":\n";
    std::cout << findings[i].id << "\n";
    std::cout << findings[i].category << "\n";
    std::cout << findings[i].description << "\n";
    std::cout << findings[i].status << "\n\n";

  }

  print_report(findings);

}