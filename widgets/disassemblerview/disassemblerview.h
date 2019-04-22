#ifndef DISASSEMBLERVIEW_H
#define DISASSEMBLERVIEW_H

#include <QProgressBar>
#include <QLineEdit>
#include <QMenu>
#include <QHexView/qhexview.h>
#include <redasm/disassembler/disassembler.h>
#include "../../models/symboltablemodel.h"
#include "../../models/segmentsmodel.h"
#include "../../dialogs/gotodialog/gotodialog.h"
#include "../graphview/disassemblergraphview/disassemblergraphview.h"
#include "../disassemblerlistingview/disassemblerlistingview.h"
#include "disassemblerviewactions.h"
#include "disassemblerviewdocks.h"
#include "../themeprovider.h"

namespace Ui {
class DisassemblerView;
}

class DisassemblerView : public QWidget
{
    Q_OBJECT

    public:
        explicit DisassemblerView(QLineEdit* lefilter, QWidget *parent = NULL);
        virtual ~DisassemblerView();
        REDasm::DisassemblerAPI *disassembler();
        void setDisassembler(REDasm::DisassemblerAPI *disassembler);
        void toggleFilter();
        void showFilter();
        void clearFilter();

    private slots:
        void changeDisassemblerStatus();
        void checkDisassemblerStatus();
        void modelIndexSelected(const QModelIndex& index);
        void checkHexEdit(int index);
        void updateCurrentFilter(int index);
        void gotoXRef(const QModelIndex &index);
        void goTo(const QModelIndex &index);
        void showModelReferences();
        void showReferences(address_t address);
        void displayAddress(address_t address);
        void displayCurrentReferences();
        void switchGraphListing();
        void switchToHexDump();
        void selectToHexDump(address_t address, u64 len);
        void showMenu(const QPoint&);
        void showGoto();
        void goForward();
        void goBack();

    private:
        ListingFilterModel* getSelectedFilterModel();
        void showListingOrGraph();
        void checkSyncGraph();
        void createActions();
        void filterSymbols();
        void syncHexEdit();

    private:
        Ui::DisassemblerView *ui;
        REDasm::DisassemblerPtr m_disassembler;
        DisassemblerViewActions* m_actions;
        DisassemblerViewDocks* m_docks;
        DisassemblerGraphView* m_graphview;
        DisassemblerListingView* m_listingview;
        QModelIndex m_currentindex;
        QHexDocument* m_hexdocument;
        QMenu* m_contextmenu;
        QLineEdit* m_lefilter;
        ListingFilterModel *m_segmentsmodel, *m_importsmodel, *m_exportsmodel, *m_stringsmodel;
        QAction* m_actsetfilter;
        QActionGroup* m_viewactions;
};

#endif // DISASSEMBLERVIEW_H
