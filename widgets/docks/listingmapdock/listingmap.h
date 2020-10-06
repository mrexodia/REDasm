#pragma once

#include <QWidget>
#include <QPixmap>
#include <rdapi/rdapi.h>
#include "../../../hooks/idisassemblercommand.h"
#include "listingmaprenderer.h"

class ListingMap : public QWidget
{
    Q_OBJECT

    public:
        explicit ListingMap(QWidget *parent = 0);
        virtual ~ListingMap();
        void linkTo(ICommand* command);
        QSize sizeHint() const override;

    private slots:
        void onRenderCompleted(const QImage& image);

    protected:
        void paintEvent(QPaintEvent*) override;
        void resizeEvent(QResizeEvent* e) override;

    private:
        RDContextPtr m_context;
        ICommand* m_command{nullptr};
        ListingMapRenderer* m_renderer{nullptr};
        RDDocument* m_document{nullptr};
        QPixmap m_pixmap;
};
