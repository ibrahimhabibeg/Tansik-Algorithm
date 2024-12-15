bool (*mathGradePriority)(Student *, Student *) = [](Student *a, Student *b) {
    if(a->getMathGrade() != b->getMathGrade())
        return a->getMathGrade() > b->getMathGrade();
    return a->getId() < b->getId();
};

bool (*scienceGradePriority)(Student *, Student *) = [](Student *a, Student *b) {
    if(a->getScienceGrade() != b->getScienceGrade())
        return a->getScienceGrade() > b->getScienceGrade();
    return a->getId() < b->getId();
};

bool (*arabicGradePriority)(Student *, Student *) = [](Student *a, Student *b) {
    if (a->getArabicGrade() != b->getArabicGrade())
        return a->getArabicGrade() > b->getArabicGrade();
    return a->getId() < b->getId();
};

bool (*englishGradePriority)(Student *, Student *) = [](Student *a, Student *b) {
    if (a->getEnglishGrade() != b->getEnglishGrade())
        return a->getEnglishGrade() > b->getEnglishGrade();
    return a->getId() < b->getId();
};

bool (*mathAndScienceWeightedPriority)(Student *, Student *) = [](Student *a, Student *b) {
    double aWeight = 0.5 * a->getMathGrade() + 0.5 * a->getScienceGrade();
    double bWeight = 0.5 * b->getMathGrade() + 0.5 * b->getScienceGrade();
    if (aWeight != bWeight)
        return aWeight > bWeight;
    return a->getId() < b->getId();
};

bool (*coverLetterPriority)(Student *, Student *) = [](Student *a, Student *b) {
    if(a->getCoverLetter() != b->getCoverLetter() && a->getCoverLetter() == "Influential")
        return true;
    else if(a->getCoverLetter() != b->getCoverLetter() && b->getCoverLetter() == "Influential")
        return false;
    return a->getId() < b->getId();
};

map<bool (*)(Student *, Student *), string> programCompartorNames = {
    {mathGradePriority, "Math Grade Priority"},
    {scienceGradePriority, "Science Grade Priority"},
    {arabicGradePriority, "Arabic Grade Priority"},
    {englishGradePriority, "English Grade Priority"},
    {mathAndScienceWeightedPriority, "Math and Science Equal Weighted Priority"},
    {coverLetterPriority, "Influential Cover Letter Priority"}
};