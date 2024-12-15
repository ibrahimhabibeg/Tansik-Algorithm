#include <vector>

using namespace std;

class Student;

enum class FacultyType
{
    Engineering,
    Medicine,
    Science,
    Arts,
    Business,
    ComputerScience,
    Pharmacy,
    Dentistry,
    Law,
    Agriculture,
    Nursing,
    Education,
    PhysicalTherapy,
    VeterinaryMedicine
};

map<FacultyType, string> facultyTypeNames = {
    {FacultyType::Engineering, "Engineering"},
    {FacultyType::Medicine, "Medicine"},
    {FacultyType::Science, "Science"},
    {FacultyType::Arts, "Arts"},
    {FacultyType::Business, "Business"},
    {FacultyType::ComputerScience, "Computer Science"},
    {FacultyType::Pharmacy, "Pharmacy"},
    {FacultyType::Dentistry, "Dentistry"},
    {FacultyType::Law, "Law"},
    {FacultyType::Agriculture, "Agriculture"},
    {FacultyType::Nursing, "Nursing"},
    {FacultyType::Education, "Education"},
    {FacultyType::PhysicalTherapy, "Physical Therapy"},
    {FacultyType::VeterinaryMedicine, "Veterinary Medicine"}};

enum class City
{
    Cairo,
    Giza,
    Alexandria,
    PortSaid,
    Ismailia,
    Suez,
    Luxor,
    Aswan,
    Asyut,
    Sohag,
    Mansoura
};

map<City, string> cityNames = {
    {City::Cairo, "Cairo"},
    {City::Giza, "Giza"},
    {City::Alexandria, "Alexandria"},
    {City::PortSaid, "Port Said"},
    {City::Ismailia, "Ismailia"},
    {City::Suez, "Suez"},
    {City::Luxor, "Luxor"},
    {City::Aswan, "Aswan"},
    {City::Asyut, "Asyut"},
    {City::Sohag, "Sohag"},
    {City::Mansoura, "Mansoura"}};

enum class UniversityType
{
    Public,
    Private,
    International,
    National
};

map<UniversityType, string> universityTypeNames = {
    {UniversityType::Public, "Public"},
    {UniversityType::Private, "Private"},
    {UniversityType::International, "International"},
    {UniversityType::National, "National"}};

enum class University
{
    CairoUniversity,
    AinShamsUniversity,
    AlexandriaUniversity,
    PortSaidUniversity,
    SuezCanalUniversity,
    AswanUniversity,
    AsyutUniversity,
    SohagUniversity,
    MansouraUniversity,
    HelwanUniversity,
    AmericanUniversityInCairo,
    BritishUniversityInEgypt,
    GermanUniversityInCairo,
    GermanInternationalUniversity,
    MisrInternationalUniversity,
    MisrUniversityForScienceAndTechnology,
    NileUniversity,
    ZewailCityOfScienceAndTechnology
};

map<University, string> universityNames = {
    {University::CairoUniversity, "Cairo University"},
    {University::AinShamsUniversity, "Ain Shams University"},
    {University::AlexandriaUniversity, "Alexandria University"},
    {University::PortSaidUniversity, "Port Said University"},
    {University::SuezCanalUniversity, "Suez Canal University"},
    {University::AswanUniversity, "Aswan University"},
    {University::AsyutUniversity, "Asyut University"},
    {University::SohagUniversity, "Sohag University"},
    {University::MansouraUniversity, "Mansoura University"},
    {University::HelwanUniversity, "Helwan University"},
    {University::AmericanUniversityInCairo, "American University In Cairo"},
    {University::BritishUniversityInEgypt, "British University In Egypt"},
    {University::GermanUniversityInCairo, "German University In Cairo"},
    {University::GermanInternationalUniversity, "German International University"},
    {University::MisrInternationalUniversity, "Misr International University"},
    {University::MisrUniversityForScienceAndTechnology, "Misr University For Science And Technology"},
    {University::NileUniversity, "Nile University"},
    {University::ZewailCityOfScienceAndTechnology, "Zewail City Of Science And Technology"}};

class Program
{
private:
    int id;
    FacultyType facultyType;
    City city;
    int rank;
    UniversityType universityType;
    University university;
    int capacity;

    bool (*comparator)(Student *, Student *);
    vector<Student *> students;

public:
    Program()
    {
    }

    Program(int id, FacultyType facultyType, City city, int rank, UniversityType universityType, University university,
            int capacity, bool (*comparator)(Student *, Student *))
    {
        this->id = id;
        this->facultyType = facultyType;
        this->city = city;
        this->rank = rank;
        this->universityType = universityType;
        this->university = university;
        this->capacity = capacity;
        this->comparator = comparator;
    }

    int getId()
    {
        return id;
    }

    FacultyType getFacultyType()
    {
        return facultyType;
    }

    City getCity()
    {
        return city;
    }

    int getRank()
    {
        return rank;
    }

    UniversityType getUniversityType()
    {
        return universityType;
    }

    University getUniversity()
    {
        return university;
    }

    int getCapacity()
    {
        return capacity;
    }

    bool (*getCompartor())(Student *, Student *)
    {
        return comparator;
    }

    vector<Student *> getStudents()
    {
        return students;
    }

    void setId(int id)
    {
        this->id = id;
    }

    void setFacultyType(FacultyType facultyType)
    {
        this->facultyType = facultyType;
    }

    void setCity(City city)
    {
        this->city = city;
    }

    void setRank(int rank)
    {
        this->rank = rank;
    }

    void setUniversityType(UniversityType universityType)
    {
        this->universityType = universityType;
    }

    void setUniversity(University university)
    {
        this->university = university;
    }

    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }

    void setComparator(bool (*comparator)(Student *, Student *))
    {
        this->comparator = comparator;
    }

    void addStudent(Student *student)
    {
        students.push_back(student);
    }

    bool isFull()
    {
        return students.size() == capacity;
    }
};
