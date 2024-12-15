bool (*rankComparator)(Program *, Program *) = [](Program *a, Program *b) {
    return a->getRank() < b->getRank();
};

bool (*portSaidLover)(Program *, Program *) = [](Program *a, Program *b) {
    if (a->getCity() == City::PortSaid && b->getCity() != City::PortSaid) {
        return true;
    }
    if (a->getCity() != City::PortSaid && b->getCity() == City::PortSaid) {
        return false;
    }
    return a->getId() < b->getId();
};

bool (*computerScienceEnjoyer)(Program *, Program *) = [](Program *a, Program *b) {
    if (a->getFacultyType() == FacultyType::ComputerScience && b->getFacultyType() != FacultyType::ComputerScience) {
        return true;
    }
    if (a->getFacultyType() != FacultyType::ComputerScience && b->getFacultyType() == FacultyType::ComputerScience) {
        return false;
    }
    return a->getId() < b->getId();
};

bool (*suezCanalUniversityLover)(Program *, Program *) = [](Program *a, Program *b) {
    if (a->getUniversity() == University::SuezCanalUniversity && b->getUniversity() != University::SuezCanalUniversity) {
        return true;
    }
    if (a->getUniversity() != University::SuezCanalUniversity && b->getUniversity() == University::SuezCanalUniversity) {
        return false;
    }
    return a->getId() < b->getId();
};

vector<bool (*)(Program *, Program *)> studentCompartors = {
    rankComparator, portSaidLover, computerScienceEnjoyer, suezCanalUniversityLover
};

map<bool (*)(Program *, Program *), string> studentCompartorNames = {
    {rankComparator, "Rank Comparator"},
    {portSaidLover, "Port Said University"},
    {computerScienceEnjoyer, "Computer Science"},
    {suezCanalUniversityLover, "Suez Canal University"}
};