<%@ Page language="c#" Codebehind="cpmember.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpmember" %>
<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>admincp</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<SCRIPT language="JavaScript" src="Common/JavaScript/Menu.js"></SCRIPT>
		<LINK href="Common/CSS/Default.CSS" type="text/css" rel="stylesheet">
		<LINK href="Common/CSS/menuStyleXP.CSS" type="text/css" rel="stylesheet">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<uc1:cptop id="Cptop1" runat="server"></uc1:cptop>
			<table id="Table1" style="WIDTH: 803px; HEIGHT: 780px" cellSpacing="1" cellPadding="3"
				width="803" border="0">
				<tr>
					<td vAlign="top" width="207" rowSpan="2">
						<table cellSpacing="0" cellPadding="0" width="100%" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table cellSpacing="1" cellPadding="10" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" height="498"><uc1:cpmenu id="Cpmenu1" runat="server"></uc1:cpmenu></td>
										</tr>
										<tr bgColor="#f9f9f9">
											<td height="80">
												<div align="center">
													<p><font color="#ff6633"><A href="../logout.aspx" target="_blank"><b><font color="#ff6666">�]�N�˳�</b></A></p>
												</div>
												</FONT></FONT></td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td vAlign="top" width="556">
						<table id="Table2" style="WIDTH: 550px; HEIGHT: 756px" cellSpacing="0" cellPadding="0"
							width="550" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table id="Table3" cellSpacing="1" cellPadding="8" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" align="left">
												<TABLE id="Table4" style="WIDTH: 559px; HEIGHT: 768px" cellSpacing="1" cellPadding="1"
													width="559" border="0">
													<TR>
														<TD style="WIDTH: 634px; HEIGHT: 22px" colSpan="2"><b>��̖��Ϣ��ԃ</b></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px; HEIGHT: 22px" colSpan="2">
															<table style="WIDTH: 464px; HEIGHT: 171px" width="464" border="0">
																<TR>
																	<TD style="WIDTH: 60px">��̖IDX</TD>
																	<TD>
																		<asp:textbox id="tbsuseridx" runat="server">0</asp:textbox></TD>
																</TR>
																<tr>
																	<td style="WIDTH: 60px">��̖</td>
																	<td><asp:textbox id="tbsuserid" runat="server"></asp:textbox>(ģ��ƥ��)</td>
																</tr>
																<tr>
																	<td style="WIDTH: 60px">�ܴa</td>
																	<td><asp:textbox id="tbspassword" runat="server"></asp:textbox>(ģ��ƥ��)</td>
																</tr>
																<tr>
																	<td style="WIDTH: 60px">�����ܴa</td>
																	<td><asp:textbox id="tbskey" runat="server"></asp:textbox>(ģ��ƥ��)</td>
																</tr>
																<tr>
																	<td style="WIDTH: 60px">IP</td>
																	<td><asp:textbox id="tbswebregip" runat="server"></asp:textbox>(ģ��ƥ��)</td>
																</tr>
																<tr>
																	<td style="WIDTH: 60px">EMAIL</td>
																	<td><asp:textbox id="tbsemail" runat="server" Width="256px"></asp:textbox>(ģ��ƥ��)</td>
																</tr>
																<tr>
																	<td style="WIDTH: 60px">��ɫ��</td>
																	<td><asp:textbox id="tbschaname" runat="server"></asp:textbox>(ģ��ƥ��)</td>
																</tr>
																<tr>
																	<td style="WIDTH: 60px; HEIGHT: 12px">���T�ȼ�</td>
																	<td style="HEIGHT: 12px"><asp:dropdownlist id="ddsweblevel" runat="server">
																			<asp:ListItem Value="9999" Selected="True">δ�x��</asp:ListItem>
																			<asp:ListItem Value="0">��ͨ���T</asp:ListItem>
																			<asp:ListItem Value="1">�S����T</asp:ListItem>
																			<asp:ListItem Value="2">�׽���T</asp:ListItem>
																			<asp:ListItem Value="3">�ʯ���T</asp:ListItem>
																		</asp:dropdownlist></td>
																</tr>
																<TR>
																	<TD style="WIDTH: 60px">�W�y���~</TD>
																	<TD><asp:textbox id="tbswebbankmin" runat="server" Width="152px">0</asp:textbox>��
																		<asp:textbox id="tbswebbankmax" runat="server" Width="152px">0</asp:textbox>֮�g</TD>
																</TR>
																<TR>
																	<TD style="WIDTH: 60px">����</TD>
																	<TD><asp:textbox id="tbswebgoldmin" runat="server" Width="152px">0</asp:textbox>��
																		<asp:textbox id="tbswebgoldmax" runat="server" Width="152px">0</asp:textbox>֮�g</TD>
																</TR>
																<TR>
																	<TD style="WIDTH: 60px; HEIGHT: 26px">�]�ԕr�g</TD>
																	<TD style="HEIGHT: 26px"><asp:textbox id="tbscreatetimestart" runat="server" Width="104px"></asp:textbox>��
																		<asp:textbox id="tbscreatetimeend" runat="server" Width="96px"></asp:textbox>֮�g(���ڸ�ʽ��2007-01-01)</TD>
																</TR>
																<TR>
																	<TD style="WIDTH: 60px"></TD>
																	<TD><asp:button id="btnsearch" runat="server" Text="��ԃ��̖��Ϣ"></asp:button>ע��ȫ�����ձ�ʾ�����еģ�Ч�ʕ��ܵ�</TD>
																</TR>
															</table>
														</TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px; HEIGHT: 22px" colSpan="2"><B>��̖��Ϣ�б�(���Ў�̖<%=rcount%>�l)</B></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px; HEIGHT: 22px" colSpan="2"><asp:datagrid id="DataGrid1" runat="server" AllowPaging="True" AutoGenerateColumns="False" Width="536px">
																<Columns>
																	<asp:BoundColumn DataField="user_idx" HeaderText="��̖���a"></asp:BoundColumn>
																	<asp:BoundColumn DataField="user_id" HeaderText="��̖"></asp:BoundColumn>
																	<asp:BoundColumn DataField="webemail" HeaderText="EMAIL"></asp:BoundColumn>
																	<asp:BoundColumn DataField="webregIP" HeaderText="�]��IP"></asp:BoundColumn>
																	<asp:BoundColumn DataField="webgold" HeaderText="����"></asp:BoundColumn>
																	<asp:BoundColumn DataField="create_time" HeaderText="�]�ԕr�g"></asp:BoundColumn>
																	<asp:ButtonColumn Text="�x��" ButtonType="PushButton" HeaderText="�x��" CommandName="Select"></asp:ButtonColumn>
																</Columns>
																<PagerStyle Mode="NumericPages"></PagerStyle>
															</asp:datagrid></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 182px; HEIGHT: 22px" colSpan="2"><B>��̖Ԕ����Ϣ</B></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 22px">��̖</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbuserid" runat="server" Width="104px" ReadOnly="True" BackColor="#E0E0E0"></asp:textbox>
															<asp:Button id="btnsearchcha" runat="server" Text="��ˎ�̖���н�ɫ"></asp:Button></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 22px">�ܴa</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbpassword" runat="server" Width="176px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 22px">�����ܴa</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbwebkey" runat="server" Width="176px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 22px">�]���]��</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:textbox id="tbwebemail" runat="server" Width="232px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 22px">�Ԅe</TD>
														<TD style="WIDTH: 636px; HEIGHT: 22px"><asp:dropdownlist id="ddsex" runat="server" Enabled="False">
																<asp:ListItem Value="����">��</asp:ListItem>
																<asp:ListItem Value="��Ů">Ů</asp:ListItem>
															</asp:dropdownlist></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 16px">VIP</TD>
														<TD style="WIDTH: 55px; HEIGHT: 16px"><asp:dropdownlist id="ddvip" runat="server">
																<asp:ListItem Value="0">��ͨ���T</asp:ListItem>
																<asp:ListItem Value="1">�S����T</asp:ListItem>
																<asp:ListItem Value="2">�׽���T</asp:ListItem>
																<asp:ListItem Value="3">�ʯ���T</asp:ListItem>
															</asp:dropdownlist></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 16px">�ȼ�</TD>
														<TD style="WIDTH: 55px; HEIGHT: 16px">
															<asp:dropdownlist id="ddlevel" runat="server">
																<asp:ListItem Value="1">��</asp:ListItem>
																<asp:ListItem Value="2">����T</asp:ListItem>
																<asp:ListItem Value="3">�_�l��</asp:ListItem>
																<asp:ListItem Value="4">GM</asp:ListItem>
																<asp:ListItem Value="5">�������</asp:ListItem>
																<asp:ListItem Value="6">��ͨ���</asp:ListItem>
																<asp:ListItem Value="10">��ֹ�Ñ�</asp:ListItem>
															</asp:dropdownlist></FONT></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 22px">����</TD>
														<TD><asp:textbox id="tbwebgold" runat="server" Width="88px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 22px">�W�y</TD>
														<TD style="WIDTH: 55px; HEIGHT: 22px"><asp:textbox id="tbwebbank" runat="server"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 26px">�]��IP</TD>
														<TD style="WIDTH: 55px; HEIGHT: 26px"><asp:textbox id="tbwebregip" runat="server" ReadOnly="True" Enabled="False" BackColor="#E0E0E0"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 19px">��������</TD>
														<TD style="WIDTH: 55px; HEIGHT: 19px"><asp:textbox id="tbcreatetime" runat="server" ReadOnly="True" Enabled="False"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 74px; HEIGHT: 27px"></TD>
														<TD style="WIDTH: 55px; HEIGHT: 27px"><asp:button id="btnedit" runat="server" Text="�޸Ď�̖��Ϣ"></asp:button></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 636px" vAlign="top" colSpan="2"></TD>
													</TR>
													<TR>
														<TD align="left" colSpan="2" style="WIDTH: 636px; HEIGHT: 19px"><FONT face="����"></FONT>
														</TD>
													</TR>
												</TABLE>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</body>
</HTML>
