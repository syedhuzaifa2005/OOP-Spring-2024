#include <iostream>
using namespace std;

class User{
protected:
	string UserName;
	string Email;
	string Password;
	string UserType;
private:
    unsigned int HashingAlgorithm(){
        unsigned int hash = 5381;
        int c;
        for (size_t i = 0; i < Password.size(); ++i){
            hash = ((hash << 5) + hash) + Password[i];
    	}
		return hash % 1000;
    }
public:
	User(){
		
	}
	User(const string& Name, const string& email, const string& password){
		UserName = Name;
		Email = email;
		Password = password;
	}
	void set_UserName(const string& Name){
		UserName = Name;
	}
	string get_UserName() const{
		return UserName;
	}
	void set_Email(const string& email){
		Email = email;
	}
	string get_Email() const{
		return Email;
	}
	void set_Password(const string& password){
		Password = password;
	}
	string get_Password(){
		return Password;
	}
	void set_UserType(const string& usertype){
		UserType = usertype;
	}
	string get_UserType(){
		return UserType;
	}
	bool VerifyUser(){
		string u;
		string e;
		string p;
		cout << "Enter Username: ";
		getline(cin, u);
		cout << "Enter E-mail: ";
		getline(cin, e),
		cout << "Enter Password: ";
		getline(cin, p);
		if(u == UserName  &&  e == Email  &&  p == Password){
			cout << "Logged in successfully!" << endl;
			return true;
		} else{
			cout << "Username, E-mail or Password is incorrect" << endl;
			return false;
		}
	}
	unsigned int hash()
    {
        Password = HashingAlgorithm();
    }
};

class Post{
protected:
	string PostID;
	string Content;
	int Likes;
	int Views;
	string Comments[100];
	int CommentsCount;
public:
	Post(const string& postID, const string& content){
		PostID = postID;
		Content = content;
		Likes = 0;
		Views = 0;
		CommentsCount = 0;
	}
	void Comment(){
		string comment;
		cout << "Enter the comment you want to add: ";
		getline(cin, comment);
		Comments[CommentsCount] = comment;
		CommentsCount++;
	}
	void DisplayComments(){
		for(int  i = 0; i < 10; i++){
			cout << "Comment " << i + 1 << ": " << Comments[i] << endl;
		}
	}
	void Like(){
		cout << "Post with ID: " << PostID << " has been liked" << endl;
		Likes++;  
	}
	void DisplayPostDetails(){
		cout << "Post Details: " << endl;
		cout << "Post ID: " << PostID << endl;
		cout << "Post Content: " << Content << endl;
		DisplayComments();
		cout << "Likes: " << Likes << endl;
		cout << "Views: " << Views << endl;
	}
	
	int get_Likes() const{
	return Likes;
	}
	void set_Likes(int L){
		Likes = L;
	}
	int get_Views() const{
	return Views;
	}
	void set_Views(int V){
		Views = V;
	}
};

class RegularUser: public User{
private:
	Post* posts;
	Post* feed;
	int NumOfPost;
	int FeedCount;
public:
	RegularUser(int numPosts, int numFeed){
		posts = new Post[numPosts]{"PostID", "Content"};
		feed = new Post[numFeed]{"PostID", "Content"};
		NumOfPost = 0;
		FeedCount = 0;
	}
	void AddPost(Post &newPost){
		if(NumOfPost < 5){
			posts[NumOfPost] = newPost;
			NumOfPost++;
		} else{
			cout << "The number of posts has reached its limit" << endl;
		}
	}
	void LikePost(Post &post){
		post.Like();
	}
	void CommentOnPost(Post &post){
		post.Comment();
	}
	void addToFeed(const Post &newPost){
		if(FeedCount < 10){
			feed[FeedCount] = newPost;
			FeedCount++;
		} else{
			cout << "Number of Posts which can be added to feed has reached its limit" << endl;
		}
	}
	void viewFeed(){
		cout << "Your Feed: " << endl;
		for(int i =0; i < 10; i++){
			feed[i].DisplayPostDetails();
		}
	}
};

class BusinessUser: public User{
private:
	Post* posts;
	Post* feed;
	int PromotedPost;
	int NumOfPost;
	int FeedCount;
public:
	BusinessUser(int numPosts, int numFeed){
		posts = new Post[numPosts]{"PostID", "Content"};
		feed = new Post[numFeed];
		PromotedPost = 0;
		NumOfPost = 0;
		FeedCount = 0;
	} 
	void promotePost(Post &post){
		if(PromotedPost < 10){
			int num1 = post.get_Likes();
			num1 = num1 * 2;
			post.set_Likes(num1);
			int num2 = post.get_Views();
			num2 = num2 * 3;
			post.set_Views(num2);
			PromotedPost++;
		} else{
			cout << "The number of posts which can be promoted has reached its limit" << endl;
		}
	}
	void AddPost(Post &newPost){
		if(NumOfPost < 10){
			posts[NumOfPost] = newPost;
			NumOfPost++;
		} else{
			cout << "The number of posts has reached its limit" << endl;
		}
	}
	void LikePost(Post &post){
		post.Like();
	}
	void CommentOnPost(Post &post){
		post.Comment();
	}
	void addToFeed(const Post &newPost){
		if(FeedCount < 10){
			feed[FeedCount] = newPost;
			FeedCount++;
		} else{
			cout << "Number of Posts which can be added to feed has reached its limit" << endl;
		}
	}
	void viewFeed(){
		cout << "Your Feed: " << endl;
		for(int i =0; i < 10; i++){
			feed[i].DisplayPostDetails();
		}
	}
};

static const int MAX_FEED_SIZE = 10;

int main(){
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl;
	bool flag1;
	
	Post RP1("Regular Post 1", "Regular Post 1 Content");
	Post RP2("Regular Post 2", "Regular Post 2 Content");
	Post RP3("Regular Post 3", "Regular Post 3 Content");
	
	RegularUser RU1(3, 8);
	
	RU1.set_UserName("Syed Huzaifa Ali");
	RU1.set_Email("k230004@nu.edu.pk");
	RU1.set_Password("huzaifaali2005");
	RU1.set_UserType("Regular");
	cout << "Regular User" << endl;
	RU1.VerifyUser();
	RU1.hash();
	if(flag1 == true){
		RU1.AddPost(RP1);
		RU1.AddPost(RP2);
		RU1.AddPost(RP3);
		
		RU1.addToFeed(RP1);
		RU1.addToFeed(RP2);
		RU1.addToFeed(RP3);
		
		RU1.CommentOnPost(RP1);
		RU1.CommentOnPost(RP2);
		RU1.CommentOnPost(RP3);
		
		RU1.LikePost(RP1);
		RU1.LikePost(RP1);
		RU1.LikePost(RP3);
		
		RU1.viewFeed();
	}
	
	bool flag2;
	
	Post BP1("Business Post 1", "Business Post 1 Content");
	Post BP2("Business Post 2", "Business Post 2 Content");
	Post BP3("Business Post 3", "Business Post 3 Content");
	
	BusinessUser BU1(8, 9);
	
	BU1.set_UserName("ABCXYZ");
	BU1.set_Email("abc@nu.edu.pk");
	BU1.set_Password("abcd1234");
	BU1.set_UserType("Business");
	cout << "Business User" << endl;
	BU1.VerifyUser();
	BU1.hash();
	if(flag2 == true){
		BU1.AddPost(BP1);
		BU1.AddPost(BP2);
		BU1.AddPost(BP3);
		
		BU1.addToFeed(BP1);
		BU1.addToFeed(BP2);
		BU1.addToFeed(BP3);
		
		BU1.CommentOnPost(BP1);
		BU1.CommentOnPost(BP2);
		BU1.CommentOnPost(BP3);
		
		BU1.LikePost(BP1);
		BU1.LikePost(BP1);
		BU1.LikePost(BP1);
		BU1.LikePost(BP2);
		BU1.LikePost(BP2);
		BU1.LikePost(BP3);
		BU1.LikePost(BP3);
		
		BU1.viewFeed();
	}
}
