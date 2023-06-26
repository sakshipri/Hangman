#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

void printgame(string str) {
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
    }
    cout << endl;
    return;
}

struct DifficultyLevel {
    string name;
    int maxTries;
};

const vector<DifficultyLevel> difficultyLevels = {
    {"Easy", 10},
    {"Medium", 6},
    {"Hard", 3}
};

int main() {
    // vector<string> dictionary = {"time", "year", "people", "way", "day", "man", "thing", "woman", "life", "child",
    //                              "world", "school", "state", "family", "student", "group", "country", "problem", "hand", "part", 
    //                              "place", "case", "week", "company", "system", "program", "question", "work", "government", "number", 
    //                              "night", "point", "home", "water", "room", "mother", "area", "money", "story", "fact", 
    //                              "month", "lot", "right", "study", "book", "eye", "job", "word", "business", "issue", 
    //                              "side", "kind", "head", "house", "service", "friend", "father", "power", "hour", "game", 
    //                              "line", "end", "member", "law", "car", "city", "community", "name", "president", "team", 
    //                              "minute", "idea", "kid", "body", "information", "back", "parent", "face", "others", "level", 
    //                              "office", "door", "health", "person", "art", "war", "history", "party", "result", "change", 
    //                              "morning", "reason", "research", "girl", "guy", "moment", "air", "teacher", "force", "education"};

    vector<string> dictionary = {"time", "way", "year", "work", "government", "day", "man", "world", "life", "part", "house", "course", "case", "system", "place", "end", "group", "company", "party", "information", "school", "fact", "money", "point", "example", "state", "business", "night", "area", "water", "thing", "family", "head", "hand", "order", "john", "side", "home", "development", "week", "power", "country", "council", "use", "service", "room", "market", "problem", "court", "lot", "a", "war", "police", "interest", "car", "law", "road", "form", "face", "education", "policy", "research", "sort", "office", "body", "person", "health", "mother", "question", "period", "name", "book", "level", "child", "control", "society", "minister", "view", "door", "line", "community", "south", "city", "god", "father", "centre", "effect", "staff", "position", "kind", "job", "woman", "action", "management", "act", "process", "north", "age", "evidence", "idea", "west", "support", "moment", "sense", "report", "mind", "church", "morning", "death", "change", "industry", "land", "care", "century", "range", "table", "back", "trade", "history", "study", "street", "committee", "rate", "word", "food", "language", "experience", "result", "team", "other", "sir", "section", "programme", "air", "authority", "role", "reason", "price", "town", "class", "nature", "subject", "department", "union", "bank", "member", "value", "need", "east", "practice", "type", "paper", "date", "decision", "figure", "right", "wife", "president", "university", "friend", "club", "quality", "voice", "lord", "stage", "king", "us", "situation", "light", "tax", "production", "march", "secretary", "art", "board", "may", "hospital", "month", "music", "cost", "field", "award", "issue", "bed", "project", "chapter", "girl", "game", "amount", "basis", "knowledge", "approach", "series", "love", "top", "news", "front", "future", "manager", "account", "computer", "security", "rest", "labour", "structure", "hair", "bill", "heart", "force", "attention", "movement", "success", "letter", "agreement", "capital", "analysis", "population", "environment", "performance", "model", "material", "theory", "growth", "fire", "chance", "boy", "relationship", "son", "sea", "record", "size", "property", "space", "term", "director", "plan", "behaviour", "treatment", "energy", "st", "peter", "income", "cup", "scheme", "design", "response", "association", "choice", "pressure", "hall", "couple", "technology", "defence", "list", "chairman", "loss", "activity", "contract", "county", "wall", "paul", "difference", "army", "hotel", "sun", "product", "summer", "set", "village", "colour", "floor", "season", "unit", "park", "hour", "investment", "test", "garden", "husband", "employment", "style", "science", "look", "deal", "charge", "help", "economy", "new", "page", "risk", "advice", "event", "picture", "commission", "fish", "college", "oil", "doctor", "opportunity", "film", "conference", "operation", "application", "press", "extent", "addition", "station", "window", "shop", "access", "region", "doubt", "majority", "degree", "television", "blood", "statement", "sound", "election", "parliament", "site", "mark", "importance", "title", "species", "increase", "return", "concern", "public", "competition", "software", "glass", "lady", "answer", "earth", "daughter", "purpose", "responsibility", "leader", "river", "eye", "ability", "appeal", "opposition", "campaign", "respect", "task", "instance", "sale", "whole", "officer", "method", "division", "source", "piece", "pattern", "lack", "disease", "equipment", "surface", "oxford", "demand", "post", "mouth", "radio", "provision", "attempt", "sector", "firm", "status", "peace", "variety", "teacher", "show", "speaker", "baby", "arm", "base", "miss", "safety", "trouble", "culture", "direction", "context", "character", "box", "discussion", "past", "weight", "organisation", "start", "brother", "league", "condition", "machine", "argument", "sex", "budget", "english", "transport", "share", "mum", "cash", "principle", "exchange", "aid", "library", "version", "rule", "tea", "balance", "afternoon", "reference", "protection", "truth", "district", "turn", "smith", "review", "minute", "duty", "survey", "presence", "influence", "stone", "dog", "benefit", "collection", "executive", "speech", "function", "queen", "marriage", "stock", "failure", "kitchen", "student", "effort", "holiday", "career", "attack", "length", "horse", "progress", "plant", "visit", "relation", "ball", "memory", "bar", "opinion", "quarter", "impact", "scale", "race", "image", "trust", "justice", "edge", "gas", "railway", "expression", "advantage", "gold", "wood", "network", "text", "forest", "sister", "chair", "cause", "foot", "rise", "half", "winter", "corner", "insurance", "step", "damage", "credit", "pain", "possibility", "legislation", "strength", "speed", "crime", "hill", "debate", "will", "supply", "present", "confidence", "mary", "patient", "wind", "solution", "band", "museum", "farm", "pound", "henry", "match", "assessment", "message", "football", "no", "animal", "skin", "scene", "article", "stuff", "introduction", "play", "administration", "fear", "dad", "proportion", "island", "contact", "japan", "claim", "kingdom", "video", "tv", "existence", "telephone", "move", "traffic", "distance", "relief", "cabinet", "unemployment", "reality", "target", "trial", "rock", "concept", "spirit", "accident", "organization", "construction", "coffee", "phone", "distribution", "train", "sight", "difficulty", "factor", "exercise", "weekend", "battle", "prison", "grant", "aircraft", "tree", "bridge", "strategy", "contrast", "communication", "background", "shape", "wine", "star", "hope", "selection", "detail", "user", "path", "client", "search", "master", "rain", "offer", "goal", "dinner", "freedom", "attitude", "while", "agency", "seat", "manner", "favour", "fig", "pair", "crisis", "smile", "prince", "danger", "call", "capacity", "output", "note", "procedure", "theatre", "tour", "recognition", "middle", "absence", "sentence", "package", "track", "card", "sign", "commitment", "player", "threat", "weather", "element", "conflict", "notice", "victory", "bottom", "finance", "fund", "violence", "file", "profit", "standard", "jack", "route", "china", "expenditure", "second", "discipline", "cell", "pp", "reaction", "castle", "congress", "individual", "lead", "consideration", "debt", "option", "payment", "exhibition", "reform", "emphasis", "spring", "audience", "feature", "touch", "estate", "assembly", "volume", "youth", "contribution", "curriculum", "appearance", "martin", "tom", "boat", "institute", "membership", "branch", "bus", "waste", "heat", "neck", "object", "captain", "driver", "challenge", "conversation", "occasion", "code", "crown", "birth", "silence", "literature", "faith", "hell", "entry", "transfer", "gentleman", "bag", "coal", "investigation", "leg", "belief", "total", "major", "document", "description", "murder", "aim", "manchester", "flight", "conclusion", "drug", "tradition", "pleasure", "connection", "owner", "treaty", "tony", "alan", "desire", "professor", "copy", "ministry", "acid", "palace", "address", "institution", "lunch", "generation", "partner", "engine", "newspaper", "cross", "reduction", "welfare", "definition", "key", "release", "vote", "examination", "judge", "atmosphere", "leadership", "sky", "breath", "creation", "row", "guide", "milk", "cover", "screen", "intention", "criticism", "jones", "silver", "customer", "journey", "explanation", "green", "measure", "brain", "significance", "phase", "injury", "run", "coast", "technique", "valley", "drink", "magazine", "potential", "drive", "revolution", "bishop", "settlement", "christ", "metal", "motion", "index", "adult", "inflation", "sport", "surprise", "pension", "factory", "tape", "flow", "iron", "trip", "lane", "pool", "independence", "hole", "un", "flat", "content", "pay", "noise", "combination", "session", "appointment", "fashion", "consumer", "accommodation", "temperature", "mike", "religion", "author", "nation", "northern", "sample", "assistance", "interpretation", "aspect", "display", "shoulder", "agent", "gallery", "republic", "cancer", "proposal", "sequence", "simon", "ship", "interview", "vehicle", "democracy", "improvement", "involvement", "general", "enterprise", "van", "meal", "breakfast", "motor", "channel", "impression", "tone", "sheet", "pollution", "bob", "beauty", "square", "vision", "spot", "distinction", "brown", "crowd", "fuel", "desk", "sum", "decline", "revenue", "fall", "diet", "bedroom", "soil", "reader", "shock", "fruit", "behalf", "deputy", "roof", "nose", "steel", "co", "artist", "graham", "plate", "song", "maintenance", "formation", "grass", "spokesman", "ice", "talk", "program", "link", "ring", "expert", "establishment", "plastic", "candidate", "rail", "passage", "joe", "parish", "ref", "emergency", "liability", "identity", "location", "framework", "strike", "countryside", "map", "lake", "household", "approval", "border", "bottle", "bird", "constitution", "autumn", "cat", "agriculture", "concentration", "guy", "dress", "victim", "mountain", "editor", "theme", "error", "loan", "stress", "recovery", "electricity", "recession", "wealth", "request", "comparison", "lewis", "white", "walk", "focus", "chief", "parent", "sleep", "mass", "jane", "bush", "foundation", "bath", "item", "lifespan", "lee", "publication", "decade", "beach", "sugar", "height", "charity", "writer", "panel", "struggle", "dream", "outcome", "efficiency", "offence", "resolution", "reputation", "specialist", "taylor", "pub", "co-operation", "port", "incident", "representation", "bread", "chain", "initiative", "clause", "resistance", "mistake", "worker", "advance", "empire", "notion", "mirror", "delivery", "chest", "licence", "frank", "average", "awareness", "travel", "expansion", "block", "alternative", "chancellor", "meat", "store", "self", "break", "drama", "corporation", "currency", "extension", "convention", "partnership", "skill", "furniture", "round", "regime", "inquiry", "rugby", "philosophy", "scope", "gate", "minority", "intelligence", "restaurant", "consequence", "mill", "golf", "retirement", "priority", "plane", "gun", "gap", "core", "uncle", "thatcher", "fun", "arrival", "snow", "no", "command", "abuse", "limit", "championship"};


    bool playAgain = true;

    while (playAgain) {
        srand(time(0));
        int x = abs(rand()) % dictionary.size();
        string picked = dictionary[x];
        
        
        string guess = "";

        for(int i = 0; i < picked.size(); i++) {
            guess = guess + "_";
        }


        int wrongs = 0;
        vector<char> guessedLetters; // Track the guessed letters

        // Select difficulty level
        int levelChoice;
        cout << "Select the difficulty level:" << endl;
        for (int i = 0; i < difficultyLevels.size(); i++) {
            cout << i + 1 << ". " << difficultyLevels[i].name << endl;
        }
        cin >> levelChoice;
        while (levelChoice < 1 || levelChoice > difficultyLevels.size()) {
            cout << "Invalid choice. Choose again." << endl;
            cin >> levelChoice;
        }
        cout << "This is a " << picked.size() << " letter word."<< endl;
        printgame(guess);


        const DifficultyLevel& chosenLevel = difficultyLevels[levelChoice - 1];
        cout << "You have maximum " << chosenLevel.maxTries << " guesses" << endl;

        while (wrongs < chosenLevel.maxTries && guess != picked) {
            char ltr;
            cout << "Enter a letter: ";
            cin >> ltr;
            bool alreadyGuessed = false;

            // Check if the letter has already been guessed using a traditional for loop
            for (int i = 0; i < guessedLetters.size(); i++) {
                if (guessedLetters[i] == ltr) {
                    alreadyGuessed = true;
                    break;
                }
            }

            if (alreadyGuessed) {
                cout << "You have already guessed the letter '" << ltr << "'. Try again." << endl;
                continue;
            }

            guessedLetters.push_back(ltr);

            int used = 0;
            for(int j = 0; j < picked.size(); j++) {
                if (ltr == picked[j]) {
                    guess[j] = ltr;
                    used++;
                }
            }

            if (used == 0) {
                cout << "Wrong guess" << endl;
                wrongs++;
            }

            cout << guess << endl;
        }

        if (wrongs == chosenLevel.maxTries) {
            cout << guess << endl;
        }
        if (wrongs < chosenLevel.maxTries) {
            cout << "You won" << endl;
            cout << "The word is " << guess << endl;
        }
        else {
            cout << "You lose" << endl;
            cout << "The word was "<< picked << endl;
        }

        char playAgainChoice;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgainChoice;

        if (playAgainChoice != 'Y' && playAgainChoice != 'y') {
            playAgain = false;
        }
    }

    return 0;
}