#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/**
 * @brief onError - print message and close app
 * @param msg : string - message to print before app closes
 */
void onError(const string& msg){
    cerr << msg << endl;
    exit(-1);
}

/**
 * @brief The Key class
 */
class Key{
private:
    /**
     * @brief priv - private key
     * @brief pub - public key
     */
    long priv,pub;

    /**
     * @brief isPrime - check if number is prime
     * @param n : long - number to check
     * @return bool : is number prime - true, otherwise false
     */
    bool isPrime(long n){
        if (n <= 1)
            return false;
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
public:
    Key(){} // empty constructor

    /**
     * @brief Key - constructor to generate key
     * @param base : long - base number (prime)
     * @param mod  : long - mod number (prime)
     * @param priv : long - private key (must be less than mod)
     */
    Key(long base,long mod, long priv){
        this->priv = priv;
        if(isPrime(base) && isPrime(mod)){
            this->pub = (long)(std::pow(base,priv)) % mod;
        }else{
            this->pub = 0;
            onError("base and mod must be prime nums");
        }
    }

    /**
     * @brief getPub - return public key
     * @return long
     */
    long getPub(){
        return this->pub;
    }

    /**
     * @brief getSecret - generate secret and return it
     * @param pub : long - public key
     * @param mod : long - mod number (prime)
     * @return long
     */
    long getSecret(long pub,long mod){
        return (long)pow(pub,this->priv) % mod;
    }
};

/**
 * @brief push - encrypt or decrypt message using own key and anothers public key
 * @param a : bool - true to encrypt, false to decrypt
 * @param k : Key - your key
 * @param pub : long - public key of your opponent
 * @param mod : long - mod num (prime)
 * @param msg : string - message
 * @return : string
 */
string push(bool a,Key k, long pub,long mod,string msg){
    long s = k.getSecret(pub,mod);
    string data;
    if(!a) s *= -1;
    for(char c : msg){
      if(c != ' '){
        char d = c <= 'Z' ? 'A' : 'a';
        int ci = std::abs(c - d) + s % 26;
        if(ci < 0 ) ci += 25;
        if(ci > 25) ci -= 25;
        data += (char)(d + ci);
      }else
        data += " ";
    }
    return data;
}

/**
 * @brief load - ask user and take input from keyboard
 * @param m : string - question
 * @return value (T)
 */
template<class T> T load(const string& m){
    T t;
    cout << m << " : ";
    cin >> t;
    return t;
}

/**
 * @brief main - main function
 * @param argc - amount of arguments
 * @param argv - array of arguments
 * @return
 */
int main(int argc,char** argv){
    long base = load<long>("Type your base");
    long mod = load<long>("Type your mod");
    long priv = load<long>("Type your private Key");

    Key k(base,mod,priv);
    cout << "Your public key : " << k.getPub() << endl;

    string msg = load<string>("Type message");
    long pub = load<long>("Enter public Key from your friend");
    bool q;
    string t = load<string>("Type E to encode or D to decode message");
    if(t == "E")
        q = true;
    else if(t == "D")
        q = false;
    else
        onError("You shold enter E or D...\n Exiting");

    cout << push(q,k,pub,mod,msg) << endl;

    return 0;
}
