#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QAbstractListModel>
#include <vector>


class GameBoard : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int dimension READ dimension CONSTANT);//через READ указываем getеры и setеры, но здесь переменная const
    Q_PROPERTY(int hiddenElementValue READ boardSize CONSTANT);


public:
    static constexpr size_t defaiiltPuzzleDimension {4};
    GameBoard( const size_t boardDimension = defaiiltPuzzleDimension,
               QObject* parent = nullptr);

    struct Tile{
        size_t value{};
        Tile& operator=(const size_t newValue){
            value = newValue;
            return *this;
        }
        bool operator==(const size_t other){
            return other == value;
        }
    };

    void shuffle();

    int rowCount(const QModelIndex& parent = QModelIndex {}) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE bool move(int index);
    using Position = std::pair<size_t,size_t>;

    size_t dimension() const;
    size_t boardSize() const;

private:
    bool isPositionValid(const size_t position) const;
    bool isBoardValid() const;

    std::vector<Tile> m_rawBoard;//какой-то мембер
    const size_t m_dimension;
    const size_t m_boardSize;
    Position getRowCol(size_t index) const;
};

#endif // GAMEBOARD_H
