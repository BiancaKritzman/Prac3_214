//Component 
class MusicFestivalObserver {
    public:
        virtual ~MusicFestivalObserver() = default;
        virtual void add(MusicFestivalObserver* child) = 0;
        virtual void remove(MusicFestivalObserver* child) = 0;
        virtual void describe() = 0;
};