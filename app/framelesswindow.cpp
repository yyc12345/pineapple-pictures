// SPDX-FileCopyrightText: 2022 Gary Wang <wzc782970009@gmail.com>
// SPDX-FileCopyrightText: 2023 Tad Young <yyc12321@outlook.com>
//
// SPDX-License-Identifier: MIT

#include "framelesswindow.h"

#include <QMouseEvent>
#include <QHoverEvent>
#include <QApplication>
#include <QVBoxLayout>
#include <QWindow>

FramelessWindow::FramelessWindow(QWidget *parent)
    : QWidget(parent)
    , m_centralLayout(new QVBoxLayout(this))
{
    this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    m_centralLayout->setContentsMargins(QMargins(0, 0, 0, 60));
}

void FramelessWindow::setCentralWidget(QWidget *widget)
{
    if (m_centralWidget) {
        m_centralLayout->removeWidget(m_centralWidget);
        m_centralWidget->deleteLater();
    }

    m_centralLayout->addWidget(widget);
    m_centralWidget = widget;
}
