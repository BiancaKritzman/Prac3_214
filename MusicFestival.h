//Component 
class MusicFestival {
    public:
        virtual ~MusicFestival() = default;
        virtual void add(MusicFestival newNode) = 0;
        virtual void remove(MusicFestival newNode) = 0;
        //some operation leaves will inherit
};